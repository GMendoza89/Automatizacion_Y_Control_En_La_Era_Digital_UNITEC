import numpy as np
import matplotlib.pyplot as plt

#Tiempo continuo

t = np.arange(-25,25,0.01) # tiempo en milisegundos
xa = 120*np.cos(0.1*np.pi*t) # señal electrica continua
# plt.stem(n,xn,'r')
plt.ylabel("A Voltios")
plt.xlabel("tiempo ms")
plt.plot(t,xa)
plt.grid()
plt.show()
#------------------------------Grafica en tiempo discreto

n = np.arange(-25,25,0.1) # tiempo en milisegundos
xn = 120*np.cos(0.1*np.pi*n) # señal electrica continua
plt.axis([-25,25, -125, 125]) # Definimos coordenadas
plt.stem(n,xn,'r')
plt.ylabel("A Voltios")
plt.xlabel("tiempo ms")
#plt.plot(t,xa)
plt.grid()
plt.show()

#------------------------------Grafica en de barras
# n = np.arange(-25,25,5) # tiempo en milisegundos
# xn = 120*np.cos(0.1*np.pi*n) # señal electrica continua
# plt.axis([-25,25, -125, 125]) # Definimos coordenadas
# plt.stem(n,xn,'r')
# plt.ylabel("A Voltios")
# plt.xlabel("tiempo ms")
# #plt.plot(t,xa)
# plt.grid()
# plt.show()

# n = np.arange(-25,25,2) # tiempo en milisegundos
# xn = 120*np.cos(0.1*np.pi*n) # señal electrica continua
# plt.axis([-25,25, -125, 125]) # Definimos coordenadas
# plt.stem(n,xn,'r')
# plt.ylabel("A Voltios")
# plt.xlabel("tiempo ms")
# #plt.plot(t,xa)
# plt.grid()
# plt.show()