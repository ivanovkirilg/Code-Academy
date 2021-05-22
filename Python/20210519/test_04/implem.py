class Counter():
    def countLetters(self, text: str):
        let, dig = 0, 0
        for c in text:
            if c.isalpha():
                let += 1
            elif c.isdigit():
                dig += 1
        
        return f"LETTERS {let}\n" + f"DIGITS {dig}"
