#!/usr/bin/python3

from typing import Callable
import json
from threading import Lock
from concurrent import futures


def printFirst():
    print("first", end="")


def printSecond():
    print("second", end="")


def printThird():
    print("third", end="")


class Foo:
    firstJobDone = Lock()
    secondJobDone = Lock()

    def __init__(self):
        Foo.firstJobDone = Lock()
        Foo.secondJobDone = Lock()
        Foo.firstJobDone.acquire()
        Foo.secondJobDone.acquire()

    def first(self, printFirst: 'Callable[[], None]') -> None:
        # printFirst() outputs "first".
        printFirst()
        # Notify the thread that is waiting for the first job to be done.
        Foo.firstJobDone.release()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        # Wait for the first job to be done
        with Foo.firstJobDone:
            # printSecond() outputs "second".
            printSecond()
            # Notify the thread that is waiting for the second job to be done.
        Foo.secondJobDone.release()

    def third(self, printThird: 'Callable[[], None]') -> None:

        # Wait for the second job to be done.
        with Foo.secondJobDone:
            # printThird() outputs "third".
            printThird()


arr = json.loads(input())

sol = Foo()


future_list = []
with futures.ThreadPoolExecutor(max_workers=4) as executor:
    for n, i in enumerate(arr):
        f = None
        if i == 1:
            f = executor.submit(sol.first, printFirst)
        elif i == 2:
            f = executor.submit(sol.second, printSecond)
        else:
            f = executor.submit(sol.third, printThird)
        future_list.append(f)
    _ = futures.as_completed(fs=future_list)
