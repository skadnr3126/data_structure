#include <iostream>
#include <string>


template <typename key_type , typename value_type>
class dictionary{

    typedef struct key_value{
        key_type key;
        value_type *value;
    
    }key_value;

    int table_size;
    key_value *tables;

    dictionary(){
        table_size = 50;
        tables = new key_value[table_size];
    }
    dictionary(int table_size){
        table_size = table_size;
        tables = new key_value[table_size];
    }

    int int_hash(int key){
        return key/table_size;
    }
    int string_hash(std::string key){
        int hash = 5381;
        for(int i =0; i < key.size(); ++i){
            hash += hash<<5 + hash +key[i];
        }
        return hash/table_size;
    }
    void insert(key_type key, value_type value){
        int index = gethash_bytype(key);
    }

    int gethas_bytype(key_type key){
        if constexpr (std::is_same<key_type , int>::vaule){
            return int_hash(key);
        }
        else if constexpr (std::is_same<key_type , std::string>::vaule){
            return string_hash(key);
        }
        else{
            static_assert(sizeof(key) == 0, "Unsupported type!");
        }

    }

    int count(key_type key){
        int index = gethash_bytype(key);

        return (tables[index] !=0);
    }
    value_type* find(key_type key){ // value_type으로 했을때 else문에서 반환값을 결정하지 못함 그래서 value_type* 하고 null을 반환하는 방식을 채택
        int index = gethash_bytype(key);
        if(tables[index]){
            return &tables[index];
        }
        else{
            return nullptr;
        }
    }
};


int main(){
    
    

}