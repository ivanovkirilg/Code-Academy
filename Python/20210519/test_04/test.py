import unittest

from implem import Counter

class TestCounter(unittest.TestCase):

    def test_count_letters(self):
        data = ['Hello CodeAcademy-2021.',
                '123        abc',
                '!!!,---.:()'
        ]
        
        expected = ['LETTERS 16\nDIGITS 4',
                    'LETTERS 3\nDIGITS 3',
                    'LETTERS 0\nDIGITS 0'
        ]

        for i in range(len(data)):
            self.assertEqual(Counter().countLetters(data[i]), expected[i])


