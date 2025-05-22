int multiplication_hash_function(int key, int bucket_amount){
    int A = 0.618;
    return (int) ((A * key) % 1) * bucket_amount;
}