import base64
print(base64.b32decode(input().encode('utf-8')).decode('utf-8'))