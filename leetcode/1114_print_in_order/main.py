#!/usr/bin/python3

from typing import Callable
import json
from concurrent import futures


def printFirst():
    print("first", end="")


def printSecond():
    print("second", end="")


def printThird():
    print("third", end="")


class Foo:
    called = [False] * 3

    def __init__(self):
        pass

    def wait(self, num):
        while not Foo.called[num-1]:
            pass

    def first(self, printFirst: 'Callable[[], None]') -> None:
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        Foo.called[0] = True

    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.wait(1)
        # printSecond() outputs "second". Do not change or remove this line.
        printSecond()
        Foo.called[1] = True

    def third(self, printThird: 'Callable[[], None]') -> None:
        self.wait(2)
        # printThird() outputs "third". Do not change or remove this line.
        printThird()
        Foo.called[2] = True


arr = json.loads(input())

sol = Foo()

future_list = []
with futures.ThreadPoolExecutor(max_workers=4) as executor:
    for n, i in enumerate(arr):
        f = None
        if i == 1:
            f = executor.submit(fn=sol.first(printFirst), index=n)
        elif i == 2:
            f = executor.submit(fn=sol.second(printSecond), index=n)
        else:
            f = executor.submit(fn=sol.third(printThird), index=n)
        future_list.append(f)
    _ = futures.as_completed(fs=future_list)
