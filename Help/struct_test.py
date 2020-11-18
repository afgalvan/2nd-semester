import struct

packed = struct.pack('i 4s f', 10, b'John', 2500)
print(packed) 