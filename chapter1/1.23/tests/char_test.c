

int is_open(int c){
    return ((c == '(') || (c=='[') || (c =='{'));
}

int is_close(int c){
    return ((c == ')') || (c==']') || (c =='}'));
}

int match(int c, int prev){
    if (((prev == '(') && (c == ')')) || ((prev == '[')  && (c == ']')) || ((prev == '{') || (c==')'))){
        return 1;
    }
    else{
        return 0;
    }

}


if (is_open(c) && (current_state == CODE)){
    stack_idx++;
    stack[stack_idx] = c;
    // printf("popping to stack %c\n", c);
}