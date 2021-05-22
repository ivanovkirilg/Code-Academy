import unittest

from implem import Words

class TestWordSort(unittest.TestCase):

    def test_get_input(self):
        '''input: alpha gamma beta beta delta'''
        '''input: dog cat1 cat2 dog1'''
        expected = (['alpha', 'beta', 'delta', 'gamma'],
                    ['cat1', 'cat2', 'dog', 'dog1'])
        actual = (Words().getWords(), Words().getWords())
        self.assertEqual(actual, expected)

