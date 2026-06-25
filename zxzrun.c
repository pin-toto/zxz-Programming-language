#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE 1024
#define MAX_STRING 256
#define MAX_EXPR 512

char* trim(char* str) {
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    
    char* end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}

void remove_comment(char* line) {
    char* comment_start = strstr(line, ":.");
    if (comment_start) {
        *comment_start = '\0';
    }
}

void replace_operators(char* expr) {
    char* pos;
    while ((pos = strchr(expr, '#')) != NULL) {
        *pos = '/';
    }
}

double evaluate_expression(char* expr) {

    char clean_expr[MAX_EXPR];
    int j = 0;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (!isspace((unsigned char)expr[i])) {
            clean_expr[j++] = expr[i];
        }
    }
    clean_expr[j] = '\0';
    
    replace_operators(clean_expr);
    
    char* open_paren;
    while ((open_paren = strrchr(clean_expr, '(')) != NULL) {
        char* close_paren = strchr(open_paren, ')');
        if (!close_paren) break;
        
        int inner_len = close_paren - open_paren - 1;
        char inner_expr[MAX_EXPR];
        strncpy(inner_expr, open_paren + 1, inner_len);
        inner_expr[inner_len] = '\0';
        
        double inner_result = evaluate_expression(inner_expr);
        
        char result_str[MAX_EXPR];
        snprintf(result_str, sizeof(result_str), "%.10f", inner_result);
        
        char new_expr[MAX_EXPR];
        int prefix_len = open_paren - clean_expr;
        strncpy(new_expr, clean_expr, prefix_len);
        new_expr[prefix_len] = '\0';
        strcat(new_expr, result_str);
        strcat(new_expr, close_paren + 1);
        
        strcpy(clean_expr, new_expr);
    }
    
    char* pow_pos;
    while ((pow_pos = strstr(clean_expr, "**")) != NULL) {
        char left[MAX_EXPR] = {0};
        char right[MAX_EXPR] = {0};
        
        char* start_left = pow_pos - 1;
        while (start_left >= clean_expr && 
               (isdigit(*start_left) || *start_left == '.' || 
                (*start_left == '-' && (start_left == clean_expr || !isdigit(*(start_left-1)))))) {
            start_left--;
        }
        start_left++;
        
        int left_len = pow_pos - start_left;
        strncpy(left, start_left, left_len);
        left[left_len] = '\0';
        
        char* start_right = pow_pos + 2;
        char* end_right = start_right;
        while (*end_right && (isdigit(*end_right) || *end_right == '.' || 
               (*end_right == '-' && (end_right == start_right || !isdigit(*(end_right-1)))))) {
            end_right++;
        }
        int right_len = end_right - start_right;
        strncpy(right, start_right, right_len);
        right[right_len] = '\0';
        
        double left_val = atof(left);
        double right_val = atof(right);
        double result = pow(left_val, right_val);
        
        char result_str[MAX_EXPR];
        snprintf(result_str, sizeof(result_str), "%.10f", result);
        
        char new_expr[MAX_EXPR];
        int prefix_len = start_left - clean_expr;
        strncpy(new_expr, clean_expr, prefix_len);
        new_expr[prefix_len] = '\0';
        strcat(new_expr, result_str);
        strcat(new_expr, end_right);
        
        strcpy(clean_expr, new_expr);
    }
    
    double values[MAX_EXPR];
    char ops[MAX_EXPR];
    int val_count = 0;
    int ops_count = 0;
    
    char* ptr = clean_expr;
    while (*ptr) {

        if (*ptr == '-' && (ptr == clean_expr || !isdigit(*(ptr-1)) && *(ptr-1) != '.')) {
            char* start = ptr;
            char num[MAX_EXPR] = {0};
            int i = 0;
            while (*ptr && (isdigit(*ptr) || *ptr == '.' || 
                   (*ptr == '-' && ptr == start))) {
                num[i++] = *ptr;
                ptr++;
            }
            values[val_count++] = atof(num);
        }
        else if (isdigit(*ptr) || *ptr == '.') {
            char num[MAX_EXPR] = {0};
            int i = 0;
            while (*ptr && (isdigit(*ptr) || *ptr == '.')) {
                num[i++] = *ptr;
                ptr++;
            }
            values[val_count++] = atof(num);
        }
        else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
            ops[ops_count++] = *ptr;
            ptr++;
        }
        else {
            ptr++;
        }
    }
    
    if (val_count == 0) return 0;
    if (val_count == 1) return values[0];
    
    int i = 0;
    while (i < ops_count) {
        if (ops[i] == '*' || ops[i] == '/') {
            if (ops[i] == '*') {
                values[i] = values[i] * values[i + 1];
            } else {
                if (values[i + 1] == 0) {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                values[i] = values[i] / values[i + 1];
            }
            for (int j = i + 1; j < val_count - 1; j++) {
                values[j] = values[j + 1];
            }
            val_count--;
            for (int j = i; j < ops_count - 1; j++) {
                ops[j] = ops[j + 1];
            }
            ops_count--;
            i--;
        }
        i++;
    }
    
    double result = values[0];
    for (i = 0; i < ops_count; i++) {
        if (ops[i] == '+') {
            result += values[i + 1];
        } else if (ops[i] == '-') {
            result -= values[i + 1];
        }
    }
    
    return result;
}

int execute_print(char* line) {
    char* trimmed = trim(line);
    
    if (strstr(trimmed, "zxz.cout") != trimmed) {
        return 0;
    }
    
    char* after_cout = trimmed + 8;
    
    if (*after_cout != '/') {
        return 0;
    }
    after_cout++;
    
    char* start_quote = strchr(after_cout, '"');
    if (start_quote) {
        start_quote++;
        char* end_quote = strchr(start_quote, '"');
        if (!end_quote) return 0;
        
        int length = end_quote - start_quote;
        char text[MAX_STRING];
        strncpy(text, start_quote, length);
        text[length] = '\0';
        
        char* after_quote = end_quote + 1;
        if (*after_quote != '/') return 0;
        after_quote++;
        if (*after_quote != ';') return 0;
        after_quote++;
        
        while (isspace((unsigned char)*after_quote)) after_quote++;
        if (*after_quote != '\0') return 0;
        
        printf("%s\n", text);
        return 1;
    }
    
    char* expr_start = after_cout;
    char* expr_end = strchr(expr_start, '/');
    if (!expr_end) return 0;
    
    int expr_len = expr_end - expr_start;
    char expr[MAX_EXPR];
    strncpy(expr, expr_start, expr_len);
    expr[expr_len] = '\0';
    
    char* after_expr = expr_end + 1;
    if (*after_expr != ';') return 0;
    after_expr++;
    
    while (isspace((unsigned char)*after_expr)) after_expr++;
    if (*after_expr != '\0') return 0;
    
    double result = evaluate_expression(expr);
    
    if (result == (int)result) {
        printf("%d\n", (int)result);
    } else {
        printf("%g\n", result);
    }
    
    return 1;
}


int check_start(char* line) {
    char* trimmed = trim(line);
    if (strcmp(trimmed, "start zxz;") == 0) {
        return 1;
    }
    return 0;
}

int check_end(char* line) {
    char* trimmed = trim(line);
    if (strcmp(trimmed, "zxz end;") == 0) {
        return 1;
    }
    return 0;
}

void show_help() {
    printf("ZXZ Interpreter v2.0\n");
    printf("Usage: zxzrun <filename.zxz>\n");
}

void show_version() {
    printf("ZXZ Interpreter v2.0\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error: No input file specified\n");
        printf("Usage: zxzrun <filename.zxz>\n");
        return 1;
    }
    
    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        show_help();
        return 0;
    }
    
    if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) {
        show_version();
        return 0;
    }
    
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error: Cannot open file '%s'\n", filename);
        return 1;
    }
    
    char line[MAX_LINE];
    int line_number = 0;
    int started = 0;
    int ended = 0;
    int has_error = 0;
    
    while (fgets(line, sizeof(line), file)) {
        line_number++;
        line[strcspn(line, "\n")] = '\0';
        remove_comment(line);
        
        char* trimmed = trim(line);
        if (strlen(trimmed) == 0) continue;
        
        if (!started) {
            if (check_start(line)) {
                started = 1;
                continue;
            } else {
                printf("Error at line %d: Program must start with 'start zxz;'\n", line_number);
                has_error = 1;
                break;
            }
        }
        
        if (check_end(line)) {
            ended = 1;
            break;
        }
        
        if (execute_print(line)) {
            continue;
        }
        
        printf("Error at line %d: Invalid syntax\n", line_number);
        printf("Found: '%s'\n", trim(line));
        has_error = 1;
        break;
    }
    
    fclose(file);
    
    if (has_error) return 1;
    if (!started) {
        printf("Error: Program did not start properly\n");
        return 1;
    }
    if (!ended) {
        printf("Error: Program must end with 'zxz end;'\n");
        return 1;
    }
    
    return 0;
}
