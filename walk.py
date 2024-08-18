import matplotlib.pyplot as plt
import numpy as np

x, y = np.loadtxt("walk.dat", unpack = True, usecols = (0,1))

plt.plot(x, y, '-')
plt.plot(x[0],y[0], 'go', label = 'start')
plt.plot(x[-1], y[-1], 'ro', label = 'end')

plt.legend()

plt.show()