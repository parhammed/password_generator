from string import ascii_lowercase, digits, ascii_uppercase
from typing import Iterable
import random


def random_str(length: int = None, *, chars: Iterable = frozenset((ascii_lowercase, digits, ascii_uppercase)), r: random.Random = random) -> str:
    length = length or r.randint(20, 30)
    out = []
    all_ = ""
    for x in chars:
        out.append(r.choice(x))
        all_ += x
        length -= 1
    out.extend(r.choices(all_, k=length))
    r.shuffle(out)
    return "".join(out)


if __name__ == "__main__":
    from pyperclip import copy

    copy(random_str())
