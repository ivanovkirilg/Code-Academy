import unittest

class TestClass(unittest.TestCase):
    def test_case_01(self):
        """This is a test that fails."""
        if True:
            self.fail()
