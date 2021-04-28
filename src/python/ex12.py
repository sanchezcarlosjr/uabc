import math
import re

switcher = {
    "+": lambda a,b : a+b,
    "-": lambda a,b : a-b,
    "/": lambda a,b : a/b,
    "%": lambda a,b : a % b,
    "*": lambda a,b : a * b,
    "": lambda a,b : a 
}

class Calculator:
    ans=0
    operation=""
    def factoryOperation(self):
        operation=input("")
        self.operation = re.findall('[+-/*%]', operation)[0]
        self.numbers = re.split("[+-/*%]",operation) 

    def calculate(self):
        a = self.ans if self.numbers[0] == "ans" else int(self.numbers[0])
        b = self.ans if self.numbers[1] == "ans" else int(self.numbers[1])
        result=switcher.get(self.operation, "Invalid operation")(a,b)
        self.ans = result
        print(result)

calculator = Calculator()

while(True):
    calculator.factoryOperation()
    calculator.calculate()
