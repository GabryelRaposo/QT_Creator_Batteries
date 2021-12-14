[![author](https://img.shields.io/badge/author-GabryelRaposo-black.svg)](https://github.com/GabryelRaposo)
[![author](https://img.shields.io/badge/author-RafaelBenatti-red.svg)](https://github.com/rs-benatti) 
[![](https://img.shields.io/badge/C++-pink.svg)](https://isocpp.org/)

# Battery Charging and Discharging Data Analysis 
A serious problem in the construction of electronic devices is the correct selection of the power source. In these types of
devices, lithium-ion batteries are commonly used nowadays, and in particular their variety—lithium
iron phosphate battery—LiFePO4. In that perspective, this project was developed to analyse the Charging and Discharging Process of LiFePO4 Battery,
creating a GUI in QT CREATOR, which, by introducing a CSV file of the battery parameters allows the user to draw graphics and analyse them. 


# Data Base Description

The database to be used in this work will be produced by researchers Yuviny
Echevarría Cartaya, Luciano Sánchez Ramos and Cecilio Blanco Viejo from the Universidad de Oviedo.
The data is available on https://data.mendeley.com/datasets/r4n22f4jfk/1

The battery tested was a LiFePO4 (LFP) type with the following characteristics:
- Operating voltage: 3.2 V
- The discharge and charge cut-off
voltages): 2.5 V and 3.65 V, respectively.
- Dimensions: height 275mm, length 166.5mm and width 13.3mm.
- Weight: 1010 g.

Full charge and discharge cycles were applied in current
constant at a C/25 rate.
- C/25 means that the charge/discharge current is equal to the capacity of the
battery (C) divided by 25. In this case, the tested battery has capacity C = 42Ah, 
so the constant current used will be approximately 1.68 A (42/25=1.68). 
There are other rates such as: C/3, C/2 and C.

Below you can see the first lines of the DataFrame:

|      I |   TA |      VB |   TB |
|-------:|-----:|--------:|-----:|
| 1.6803 | 24.1 | 2.79234 | 24.1 |
| 1.6797 | 24.1 | 2.79377 | 24.1 |
| 1.6797 | 24.1 | 2.79482 | 24.1 |
| 1.6797 | 24.1 | 2.79602 | 24.1 |
| 1.6797 | 24.1 | 2.79663 | 24.1 |

In the c25.csv file there are 4 columns, namely:
- I = battery current
- TA = room temperature
- VB = battery voltage
- TB = battery temperature

# Project development



