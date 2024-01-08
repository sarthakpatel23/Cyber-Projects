import hashlib

plaintext=input("enter your input value:-")
hash_value=hashlib.sha224(plaintext.encode())
print("hash value is:-"+ hash_value.hexdigest())

# hash_value2=hashlib.sha256(plaintext.encode())
# print("hash value is:-"+hash_value2.hexdigest())