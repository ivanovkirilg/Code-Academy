import unittest

from wordsort import WordSort

class TestWordSort(unittest.TestCase):
    def test_get_input_1(self):
        '''input: without,hello,bag,world'''
        expected = ['bag','hello','without','world']
        actual = WordSort().getInput()
        print('actual:  ', actual)
        print('expected:', expected)
        self.assertEqual(actual, expected)

