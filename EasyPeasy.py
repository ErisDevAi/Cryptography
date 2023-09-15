def decrypt(key_location, encrypted_data):
    kf = open(KEY_FILE, "rb").read()

    start = key_location
    stop = key_location + len(encrypted_data) // 2

    if stop >= KEY_LEN:
        stop = stop % KEY_LEN
        key = kf[start:] + kf[:stop]
    else:
        key = kf[start:stop]

    key_location = stop

    decrypted_data = ''.join([chr(int(encrypted_data[i:i+2], 16) ^ key[i])
                             for i in range(len(encrypted_data) // 2)])
    return key_location, decrypted_data


key_location = 0
encrypted_data = input("Nhập chuỗi mã hóa (hex): ").strip()
key_location, decrypted_data = decrypt(key_location, encrypted_data)
print("Đây là thông điệp đã giải mã: " + decrypted_data)
