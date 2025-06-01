int modulo_hash_function(int key, int bucket_amount){
    return key % bucket_amount;
}

int multiplication_hash_function(int key, int bucket_amount){
    int A = 1.618;
    return (int) ((A * key) % 1) * bucket_amount;
}