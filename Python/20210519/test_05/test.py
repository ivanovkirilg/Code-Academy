import unittest

from implem import *

class Tests(unittest.TestCase):
    def test_find_longest_word(self):
        text = "Tell us why you want to learn by CodeAcademy"
        assert find_longest_word(text) == "CodeAcademy"
        text = "test test1 test2  test3"
        assert find_longest_word(text) == "test1"

    def test_reverse_string(self):
        assert reverse_string("CodeAcademy") == "ymedacAedoC"

    def test_validate_dna(self): 
        assert validate_dna('CCGGAAGAGCTTACTTAGccggaagagcttacttag') 
        assert not validate_dna('xCCGGAAGAGCTTACTTAGccggaagagcttacttag')

