import os
from common.utils import run, expect_retcode


def run_test(sut, verbose, debug):
    this_dir = os.path.dirname(os.path.abspath(__file__))
    args = '-s ../graphs/invalid1.dot'.split()

    proc, out = run(sut, args, this_dir, 3, verbose, debug)

    expect_retcode(proc, 1, out, verbose, debug)
