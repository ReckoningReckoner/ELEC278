import matplotlib.pyplot as plot

filenames = ["part1.csv", "part2.csv", "part3.csv"]

for filename in filenames:
    data = open(filename)
    first_line = data.readline().strip().split(",")
    n = []
    values = []
    names = first_line[1:]

    for i in range(len(first_line) - 1):
        values.append([])

    for i in range(5):
        line = data.readline().strip().split(",")
        n.append(line[0])
        for j in range(1, len(line)):
            time = float(line[j].strip())
            values[j-1].append(time)

    plot.figure()
    for i in range(len(names)):
        plot.plot(n, values[i], label=names[i])
        plot.xlabel("Size of array")
        plot.ylabel("Time to sort (s)")
        plot.legend(loc=2)

    plot.savefig(filename.split(".")[0] + ".png")
