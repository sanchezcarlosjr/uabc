def fact(x, y):
    if y:
        print(f"You have reached {x}.")

def assertInput(score):
    score = float(score)
    if score < 0 or score > 100:
        raise Exception("Score have be between 0 and 100.")
    return score

score = assertInput(input("What is your score? "))
fact("A", score >= 93.33)
fact("A-", score >= 90 and score < 93.33)
fact("B+", score >= 86.67 and score < 90)
fact("B", score >= 83.33 and score < 86.67)
fact("B-", score >= 80 and score < 83.33)
fact("C+", score >= 76.67 and score < 80)
fact("C", score >= 73.33 and score < 76.67)
fact("C-", score >= 70 and score < 73.33)
fact("D+", score >= 66.67 and score < 70)
fact("D", score >= 63.33 and score < 66.67)
fact("D-", score >= 60 and score < 63.33)
fact("F", score >= 0 and score < 60)
