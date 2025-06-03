int modulo_hash_function(int key, int bucket_amount){
    return key % bucket_amount;
}

int multiplication_hash_function(int key, int bucket_amount){
    const double A = 0.6180339887;
    return (int) (bucket_amount * fmod(key * A, 1.0));
}