import unittest

from sum import Sum 

class TestSum(unittest.TestCase):
    def test_sum_int_str_valid(self):
        self.assertEqual(Sum().sumIntStr('3', '4'), 7)
        self.assertEqual(Sum().sumIntStr('3', '-3'), 0)
        self.assertEqual(Sum().sumIntStr('3', '-4'), -1)
        pass
    
    def test_sum_int_str_invalid(self):
        with self.assertRaises(TypeError):
            Sum().sumIntStr('2', ['2'])
        with self.assertRaises(ValueError):
            Sum().sumIntStr('a', '2')
