long prog(long* rsi, long size, long max){
    long fibn = 0; // %r10
    long fibn1; // %r10
    rsi = fibn; // %rsi
    long* array = rsi+1; // %rax
    fibn = 1; // %r10
    *array = fibn; // %rax
    while(2 < size){
        fibn = *array // %rcx
        fibn1 = *(array-1) // %r10
        fibn += fibn1 // %r10
        if (max < fibn) { // cbl %rdi, %rcx, .L5
            return 1; // movq $1, %rax
            // ret %r11
        }
        array++; // addq $8, %rax
        *array = fibn; // movq %rcx, (%rax)
        size--; // subq $1, %size
    }
    return 0; // movq $0, %rax
            // ret %r11
}