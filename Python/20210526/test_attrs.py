import unittest


class TestClass(unittest.TestCase):
    def test_case_01(self):
        """This is a test method."""
        print('\n' + "In test_case_01()")
        print(self.id())
        print(self.shortDescription())
