from string import ascii_lowercase, digits, ascii_uppercase
import random


def random_str(length: int = None, *, chars: str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.+_", r: random.Random = random) -> str:
    return "".join(r.choices(chars, k=length or r.randint(20, 30)))


if __name__ == "__main__":
    password = random_str()
    print(password)
    
    from pyperclip import copy
    
    copy(password)
    
