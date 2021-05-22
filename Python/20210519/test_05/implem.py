def find_longest_word(s1: str):
    """
    Returns the longest word in string s1.
    In case there are several, return the first.
    """
    l1 = s1.split(' ')
    longest = ''
    
    for word in l1:
        if len(word) > len(longest):
            longest = word
    
    return longest


def reverse_string(s1: str):
    """
    Reverses order of characters in string s1
    """
    return s1[::-1]


def validate_dna(s: str):
    """
    Return True if the DNA string only contains characters
    a, c, t or g (lower- or uppercase). False otherwise.
    """
    for c in s:
        if c not in 'actgACTG':
            return False
    else:
        return True
