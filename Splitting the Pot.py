# Code of Ian Kelley for the Atlas Foundation Problems

import pandas as pd

print("Init")
out = pd.DataFrame(columns=["You", "A", "B", "C", "D"], index=range(0, (50 ** 5)))

print("DF Init")

count = 1
for i in range(0, 50):
    for i2 in range(0, 50):
        for i3 in range(0, 50):
            for i4 in range(0, 50):
                for i5 in range(0, 50):
                    p = 50 - (i + i2 + i3 + i4 + i5)
                    print(f'{i}, {i2}, {i3}, {i4}, {i5}, {p}')
                    count += 1
                    out.loc[count] = pd.Series({"You": i, "A": i2, "B": i3, "C": i4, "D": i5})

print(out)

# This code took roughly 20 minutes to get through 1/50 of the possibilities, and was re-written in C for efficiency
