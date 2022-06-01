import scipy as sp
import networkx as nx
import numpy as np

G = nx.DiGraph()

for i in range(0, 984 + 1):
    G.add_node(i)

# Lista de aristas
# ++++++++++++++++++HighwayIds
# FROM Z TO Y 1
for i in range(1, 36):
    G.add_edge(i, i + 1, w=3)
# FROM Z TO Y 2
for i in range(37, 72):
    G.add_edge(i, i + 1, w=3)
# FROM Y TO Z 1
for i in range(73, 108):
    G.add_edge(i, i + 1, w=3)
# FROM Y TO Z 2
for i in range(109, 144):
    G.add_edge(i, i + 1, w=3)

# ++++++++++++++++++BridgeIds
# Larry
for i in range(145, 150):
    G.add_edge(i, i + 1, w=6)
for i in range(955, 960):
    G.add_edge(i, i + 1, w=6)
# Curly
for i in range(151, 156):
    G.add_edge(i, i + 1, w=6)
for i in range(961, 966):
    G.add_edge(i, i + 1, w=6)
# Moe
for i in range(157, 162):
    G.add_edge(i, i + 1, w=6)
for i in range(967, 972):
    G.add_edge(i, i + 1, w=6)
# Shemp
for i in range(163, 168):
    G.add_edge(i, i + 1, w=6)
for i in range(973, 978):
    G.add_edge(i, i + 1, w=6)
# Joe
for i in range(169, 174):
    G.add_edge(i, i + 1, w=6)
for i in range(979, 984):
    G.add_edge(i, i + 1, w=6)

# ++++++++++++++++++RoundaboutIds
# Y
for i in range(180, 175, -1):
    G.add_edge(i, i - 1, w=6)
G.add_edge(175, 180, w=6)

# Z
for i in range(181, 186):
    G.add_edge(i, i + 1, w=6)
G.add_edge(186, 181, w=6)

# ++++++++++++++++++StreetIds
# A
# 1
for i in range(355, 360):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(361, 366):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(367, 372):
    G.add_edge(i, i + 1, w=6)

# 4
for i in range(373, 378):
    G.add_edge(i, i + 1, w=6)

# B
# 1
for i in range(379, 384):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(385, 390):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(391, 396):
    G.add_edge(i, i + 1, w=6)

# 4
for i in range(397, 402):
    G.add_edge(i, i + 1, w=6)

# C
# 1
for i in range(403, 408):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(409, 414):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(415, 420):
    G.add_edge(i, i + 1, w=6)

# 4
for i in range(421, 426):
    G.add_edge(i, i + 1, w=6)

# D
# 1
for i in range(427, 432):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(433, 438):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(439, 444):
    G.add_edge(i, i + 1, w=6)

# 4
for i in range(445, 450):
    G.add_edge(i, i + 1, w=6)

# E
# 1
for i in range(451, 456):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(457, 462):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(463, 468):
    G.add_edge(i, i + 1, w=6)

# 4
for i in range(469, 474):
    G.add_edge(i, i + 1, w=6)

# F
# 1
for i in range(475, 480):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(481, 486):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(487, 492):
    G.add_edge(i, i + 1, w=6)

# 4
for i in range(493, 498):
    G.add_edge(i, i + 1, w=6)

# S
# 1
for i in range(499, 504):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(505, 510):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(511, 516):
    G.add_edge(i, i + 1, w=6)

# 4
for i in range(517, 522):
    G.add_edge(i, i + 1, w=6)

# T
# 1
for i in range(523, 528):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(529, 534):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(535, 540):
    G.add_edge(i, i + 1, w=6)

# 4
for i in range(541, 546):
    G.add_edge(i, i + 1, w=6)

# U
# 1
for i in range(547, 552):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(553, 558):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(559, 564):
    G.add_edge(i, i + 1, w=6)

# 4
for i in range(565, 570):
    G.add_edge(i, i + 1, w=6)

# V
# 1
for i in range(571, 576):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(577, 582):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(583, 588):
    G.add_edge(i, i + 1, w=6)

# 4
for i in range(589, 594):
    G.add_edge(i, i + 1, w=6)

# W
# 1
for i in range(595, 600):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(601, 606):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(607, 612):
    G.add_edge(i, i + 1, w=6)

# 4
for i in range(613, 618):
    G.add_edge(i, i + 1, w=6)

# X
# 1
for i in range(619, 624):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(625, 630):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(631, 636):
    G.add_edge(i, i + 1, w=6)

# 4
for i in range(637, 642):
    G.add_edge(i, i + 1, w=6)

# G
# 1
for i in range(367, 372):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(649, 654):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(655, 660):
    G.add_edge(i, i + 1, w=6)

# H
# 1
for i in range(391, 396):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(667, 672):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(673, 678):
    G.add_edge(i, i + 1, w=6)

# I
# 1
for i in range(415, 420):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(685, 690):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(691, 696):
    G.add_edge(i, i + 1, w=6)

# J
# 1
for i in range(439, 444):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(703, 708):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(709, 714):
    G.add_edge(i, i + 1, w=6)

# K
# 1
for i in range(463, 468):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(721, 726):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(727, 732):
    G.add_edge(i, i + 1, w=6)

# L
# 1
for i in range(487, 492):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(739, 744):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(745, 750):
    G.add_edge(i, i + 1, w=6)

# M
# 1
for i in range(751, 756):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(499, 504):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(763, 768):
    G.add_edge(i, i + 1, w=6)

# N
# 1
for i in range(769, 774):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(523, 528):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(781, 786):
    G.add_edge(i, i + 1, w=6)

# O
# 1
for i in range(787, 792):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(547, 552):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(799, 804):
    G.add_edge(i, i + 1, w=6)

# P
# 1
for i in range(805, 810):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(571, 576):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(817, 822):
    G.add_edge(i, i + 1, w=6)

# Q
# 1
for i in range(823, 828):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(595, 600):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(835, 840):
    G.add_edge(i, i + 1, w=6)

# R
# 1
for i in range(841, 846):
    G.add_edge(i, i + 1, w=6)

# 2
for i in range(619, 624):
    G.add_edge(i, i + 1, w=6)

# 3
for i in range(853, 858):
    G.add_edge(i, i + 1, w=6)

# ++++++++++++++++++HighwayIds
# A
G.add_edge(859, 355, w=6)

G.add_edge(360, 860, w=6)
G.add_edge(860, 361, w=6)

G.add_edge(366, 861, w=6)
G.add_edge(861, 367, w=6)

G.add_edge(372, 862, w=6)
G.add_edge(862, 373, w=6)

G.add_edge(378, 859, w=6)

# Interconeccions
G.add_edge(860, 863, w=6)

# A001C = 859,
#    A002C = 860,
#    A003C = 861,
#    A004C = 862,
# B
G.add_edge(863, 379, w=6)

G.add_edge(384, 864, w=6)
G.add_edge(864, 385, w=6)

G.add_edge(390, 865, w=6)
G.add_edge(865, 391, w=6)

G.add_edge(396, 866, w=6)
G.add_edge(866, 397, w=6)

G.add_edge(402, 863, w=6)

# Interconeccions
G.add_edge(864, 867, w=6)
G.add_edge(866, 861, w=6)

# B001C = 863,
# B002C = 864,
# B003C = 865,
# B004C = 866,
# C
G.add_edge(867, 403, w=6)

G.add_edge(408, 868, w=6)
G.add_edge(868, 409, w=6)

G.add_edge(414, 869, w=6)
G.add_edge(869, 415, w=6)

G.add_edge(420, 870, w=6)
G.add_edge(870, 421, w=6)

G.add_edge(426, 867, w=6)

# Interconeccions
G.add_edge(868, 871, w=6)
G.add_edge(870, 865, w=6)

# C001C = 867,
# C002C = 868,
# C003C = 869,
# C004C = 870,
# D
G.add_edge(871, 427, w=6)

G.add_edge(432, 872, w=6)
G.add_edge(872, 433, w=6)

G.add_edge(438, 873, w=6)
G.add_edge(873, 439, w=6)

G.add_edge(444, 874, w=6)
G.add_edge(874, 445, w=6)

G.add_edge(450, 871, w=6)

# Interconeccions
G.add_edge(872, 875, w=6)
G.add_edge(874, 869, w=6)

# D001C = 871,
# D002C = 872,
# D003C = 873,
# D004C = 874,
# E
G.add_edge(875, 451, w=6)

G.add_edge(456, 876, w=6)
G.add_edge(876, 457, w=6)

G.add_edge(462, 877, w=6)
G.add_edge(877, 463, w=6)

G.add_edge(468, 878, w=6)
G.add_edge(878, 469, w=6)

G.add_edge(474, 875, w=6)

# Interconeccions
G.add_edge(876, 879, w=6)
G.add_edge(878, 873, w=6)

# E001C = 875,
# E002C = 876,
# E003C = 877,
# E004C = 878,
# F
G.add_edge(879, 475, w=6)

G.add_edge(480, 880, w=6)
G.add_edge(880, 481, w=6)

G.add_edge(486, 881, w=6)
G.add_edge(881, 487, w=6)

G.add_edge(492, 882, w=6)
G.add_edge(882, 493, w=6)

G.add_edge(498, 879, w=6)

# Interconeccions
G.add_edge(882, 877, w=6)

# F001C = 879,
# F002C = 880,
# F003C = 881,
# F004C = 882,

# G
# Interconeccions
G.add_edge(660, 862, w=6)
G.add_edge(861, 649, w=6)

#    G001C = 862,
#    G002C = 861,


# H
# Interconeccions
G.add_edge(678, 866, w=6)
G.add_edge(865, 667, w=6)
#    H001C = 866,
#    H002C = 865,


# I
# Interconeccions
G.add_edge(696, 870, w=6)
G.add_edge(869, 685, w=6)
#    I001C = 870,
#    I002C = 869,

# J
# Interconeccions
G.add_edge(714, 874, w=6)
G.add_edge(873, 703, w=6)
#    J001C = 874,
#    J002C = 873,


# K
# Interconeccions
G.add_edge(732, 878, w=6)
G.add_edge(877, 721, w=6)
#    K001C = 878,
#    K002C = 877,


# L
# Interconeccions
G.add_edge(750, 882, w=6)
G.add_edge(881, 739, w=6)
#    L001C = 882,
#    L002C = 881,


# M
# Interconeccions
G.add_edge(756, 909, w=6)
G.add_edge(910, 763, w=6)
#    M003C = 909,
#    M004C = 910,


# N
# Interconeccions
G.add_edge(774, 913, w=6)
G.add_edge(914, 781, w=6)
#    N003C = 913,
#    N004C = 914,


# O
# Interconeccions
G.add_edge(792, 917, w=6)
G.add_edge(918, 799, w=6)
#    O003C = 917,
#    O004C = 918,


# P
# Interconeccions
G.add_edge(810, 921, w=6)
G.add_edge(922, 817, w=6)
#    P003C = 921,
#    P004C = 922,


# Q
# Interconeccions
G.add_edge(828, 925, w=6)
G.add_edge(926, 835, w=6)
#    Q003C = 925,
#    Q004C = 926,


# R
# Interconeccions
G.add_edge(846, 929, w=6)
G.add_edge(930, 853, w=6)
#    R003C = 929,
#    R004C = 930,


# S
G.add_edge(910, 499, w=6)

G.add_edge(504, 909, w=6)
G.add_edge(909, 505, w=6)

G.add_edge(510, 933, w=6)
G.add_edge(933, 511, w=6)

G.add_edge(516, 934, w=6)
G.add_edge(934, 517, w=6)

G.add_edge(522, 910, w=6)

# Interconeccions
G.add_edge(909, 914, w=6)

# S001C = 910,
# S002C = 909,
# S003C = 933,
# S004C = 934,
# T
G.add_edge(914, 523, w=6)

G.add_edge(528, 913, w=6)
G.add_edge(913, 529, w=6)

G.add_edge(534, 937, w=6)
G.add_edge(937, 535, w=6)

G.add_edge(540, 938, w=6)
G.add_edge(938, 541, w=6)

G.add_edge(546, 914, w=6)

# Interconeccions
G.add_edge(913, 918, w=6)
G.add_edge(938, 933, w=6)

# T001C = 914,
# T002C = 913,
# T003C = 937,
# T004C = 938,
# U
G.add_edge(918, 547, w=6)

G.add_edge(552, 917, w=6)
G.add_edge(917, 553, w=6)

G.add_edge(558, 941, w=6)
G.add_edge(941, 559, w=6)

G.add_edge(564, 942, w=6)
G.add_edge(942, 565, w=6)

G.add_edge(570, 918, w=6)

# Interconeccions
G.add_edge(917, 922, w=6)
G.add_edge(942, 937, w=6)

# U001C = 918,
# U002C = 917,
# U003C = 941,
# U004C = 942,
# V
G.add_edge(922, 571, w=6)

G.add_edge(576, 921, w=6)
G.add_edge(921, 577, w=6)

G.add_edge(582, 945, w=6)
G.add_edge(945, 583, w=6)

G.add_edge(588, 946, w=6)
G.add_edge(946, 589, w=6)

G.add_edge(594, 922, w=6)

# Interconeccions
G.add_edge(921, 926, w=6)
G.add_edge(946, 941, w=6)

# V001C = 922,
# V002C = 921,
# V003C = 945,
# V004C = 946,
# W
G.add_edge(926, 595, w=6)

G.add_edge(600, 925, w=6)
G.add_edge(925, 601, w=6)

G.add_edge(606, 949, w=6)
G.add_edge(949, 607, w=6)

G.add_edge(612, 950, w=6)
G.add_edge(950, 613, w=6)

G.add_edge(618, 926, w=6)

# Interconeccions
G.add_edge(925, 930, w=6)
G.add_edge(950, 945, w=6)

# W001C = 926,
# W002C = 925,
# W003C = 949,
# W004C = 950,
# X
G.add_edge(930, 619, w=6)

G.add_edge(624, 929, w=6)
G.add_edge(929, 625, w=6)

G.add_edge(630, 953, w=6)
G.add_edge(953, 631, w=6)

G.add_edge(636, 954, w=6)
G.add_edge(954, 637, w=6)

G.add_edge(642, 930, w=6)

# Interconeccions
G.add_edge(954, 949, w=6)

# X001C = 930,
# X002C = 929,
# X003C = 953,
# X004C = 954

# +++++++++++++++++Conexion de puentes
# Larry
# G To Puente
G.add_edge(654, 145, w=6)
# Puente To H
G.add_edge(960, 673, w=6)
# Puente To M
G.add_edge(150, 751, w=6)
# N To Puente
G.add_edge(786, 955, w=6)

# Curly
# H To Puente
G.add_edge(672, 151, w=6)
# Puente To I
G.add_edge(966, 691, w=6)
# Puente To N
G.add_edge(156, 769, w=6)
# O To Puente
G.add_edge(804, 961, w=6)

# Moe
# I To Puente
G.add_edge(690, 157, w=6)
# Puente To J
G.add_edge(972, 709, w=6)
# Puente To O
G.add_edge(162, 787, w=6)
# P To Puente
G.add_edge(822, 967, w=6)

# Shemp
# J To Puente
G.add_edge(708, 163, w=6)
# Puente To K
G.add_edge(978, 727, w=6)
# Puente To P
G.add_edge(168, 805, w=6)
# Q To Puente
G.add_edge(840, 973, w=6)

# Joe
# K To Puente
G.add_edge(726, 169, w=6)
# Puente To L
G.add_edge(984, 745, w=6)
# Puente To Q
G.add_edge(174, 823, w=6)
# R To Puente
G.add_edge(858, 979, w=6)

# +++++++++++++++++Conexion de rotondas
# Y
G.add_edge(175, 655, w=6)  # Y1 - G13
G.add_edge(36, 655, w=6)  # H1 - G13
G.add_edge(36, 175, w=6)  # H1 - Y1
G.add_edge(72, 175, w=6)  # H2 - Y1

G.add_edge(768, 176, w=6)  # M18 - Y2
G.add_edge(176, 73, w=6)  # Y2 - H3
G.add_edge(768, 109, w=6)  # M18 - H4
G.add_edge(176, 109, w=6)  # Y2 - H4

# Y001R = 175,
# Y002R = 176,
# Y003R = 177,
# Y004R = 178,
# Y005R = 179,
# Y006R = 180,

# Z

G.add_edge(744, 181, w=6)  # L12 - Z1
G.add_edge(744, 1, w=6)  # L12 - H1
G.add_edge(181, 1, w=6)  # Z1 - H1
G.add_edge(181, 37, w=6)  # Z1 - H2

G.add_edge(108, 182, w=6)  # H3 - Z2
G.add_edge(144, 182, w=6)  # H4 - Z2
G.add_edge(144, 841, w=6)  # H4 - R
G.add_edge(182, 841, w=6)  # Z2 - R

# Z001R = 181,
# Z002R = 182,
# Z003R = 183,
# Z004R = 184,
# Z005R = 185,
# Z006R = 186,

# +++++++++++++++++Conexion de paradas
# A
G.add_edge(187, 357, w=6)
G.add_edge(356, 187, w=6)
# A001S = 187,
G.add_edge(188, 360, w=6)
G.add_edge(359, 188, w=6)
# A002S = 188,
G.add_edge(189, 363, w=6)
G.add_edge(362, 189, w=6)
# A003S = 189,
G.add_edge(190, 366, w=6)
G.add_edge(365, 190, w=6)
# A004S = 190,
G.add_edge(191, 369, w=6)
G.add_edge(368, 191, w=6)
# A005S = 191,
G.add_edge(192, 372, w=6)
G.add_edge(371, 192, w=6)
# A006S = 192,
G.add_edge(193, 375, w=6)
G.add_edge(374, 193, w=6)
# A007S = 193,
G.add_edge(194, 378, w=6)
G.add_edge(377, 194, w=6)
# A008S = 194,

# B
G.add_edge(195, 381, w=6)
G.add_edge(380, 195, w=6)
# B001S = 195,
G.add_edge(196, 384, w=6)
G.add_edge(383, 196, w=6)
# B002S = 196,
G.add_edge(197, 387, w=6)
G.add_edge(386, 197, w=6)
# B003S = 197,
G.add_edge(198, 390, w=6)
G.add_edge(389, 198, w=6)
# B004S = 198,
G.add_edge(199, 393, w=6)
G.add_edge(392, 199, w=6)
# B005S = 199,
G.add_edge(200, 396, w=6)
G.add_edge(395, 200, w=6)
# B006S = 200,
G.add_edge(201, 399, w=6)
G.add_edge(398, 201, w=6)
# B007S = 201,
G.add_edge(202, 402, w=6)
G.add_edge(401, 202, w=6)
# B008S = 202,

# C
G.add_edge(203, 405, w=6)
G.add_edge(404, 203, w=6)
# C001S = 203,
G.add_edge(204, 408, w=6)
G.add_edge(407, 204, w=6)
# C002S = 204,
G.add_edge(205, 411, w=6)
G.add_edge(410, 205, w=6)
# C003S = 205,
G.add_edge(206, 414, w=6)
G.add_edge(413, 206, w=6)
# C004S = 206,
G.add_edge(207, 417, w=6)
G.add_edge(416, 207, w=6)
# C005S = 207,
G.add_edge(208, 420, w=6)
G.add_edge(419, 208, w=6)
# C006S = 208,
G.add_edge(209, 423, w=6)
G.add_edge(422, 209, w=6)
# C007S = 209,
G.add_edge(210, 426, w=6)
G.add_edge(425, 210, w=6)
# C008S = 210,

# D
G.add_edge(211, 429, w=6)
G.add_edge(428, 211, w=6)
# D001S = 211,
G.add_edge(212, 432, w=6)
G.add_edge(431, 212, w=6)
# D002S = 212,
G.add_edge(213, 435, w=6)
G.add_edge(434, 213, w=6)
# D003S = 213,
G.add_edge(214, 438, w=6)
G.add_edge(437, 214, w=6)
# D004S = 214,
G.add_edge(215, 441, w=6)
G.add_edge(440, 215, w=6)
# D005S = 215,
G.add_edge(216, 444, w=6)
G.add_edge(443, 216, w=6)
# D006S = 216,
G.add_edge(217, 447, w=6)
G.add_edge(446, 217, w=6)
# D007S = 217,
G.add_edge(218, 450, w=6)
G.add_edge(449, 218, w=6)
# D008S = 218,

# E
G.add_edge(219, 453, w=6)
G.add_edge(452, 219, w=6)
# E001S = 219,
G.add_edge(220, 456, w=6)
G.add_edge(455, 220, w=6)
# E002S = 220,
G.add_edge(221, 459, w=6)
G.add_edge(458, 221, w=6)
# E003S = 221,
G.add_edge(222, 462, w=6)
G.add_edge(461, 222, w=6)
# E004S = 222,
G.add_edge(223, 465, w=6)
G.add_edge(464, 223, w=6)
# E005S = 223,
G.add_edge(224, 468, w=6)
G.add_edge(467, 224, w=6)
# E006S = 224,
G.add_edge(225, 471, w=6)
G.add_edge(470, 225, w=6)
# E007S = 225,
G.add_edge(226, 474, w=6)
G.add_edge(473, 226, w=6)
# E008S = 226,

# F
G.add_edge(227, 477, w=6)
G.add_edge(476, 227, w=6)
# F001S = 227,
G.add_edge(228, 480, w=6)
G.add_edge(479, 228, w=6)
# F002S = 228,
G.add_edge(229, 483, w=6)
G.add_edge(482, 229, w=6)
# F003S = 229,
G.add_edge(230, 486, w=6)
G.add_edge(485, 230, w=6)
# F004S = 230,
G.add_edge(231, 489, w=6)
G.add_edge(488, 231, w=6)
# F005S = 231,
G.add_edge(232, 492, w=6)
G.add_edge(491, 232, w=6)
# F006S = 232,
G.add_edge(233, 495, w=6)
G.add_edge(494, 233, w=6)
# F007S = 233,
G.add_edge(234, 498, w=6)
G.add_edge(497, 234, w=6)
# F008S = 234,

# S
G.add_edge(235, 501, w=6)
G.add_edge(500, 235, w=6)
# S001S = 235,
G.add_edge(236, 504, w=6)
G.add_edge(503, 236, w=6)
# S002S = 236,
G.add_edge(237, 507, w=6)
G.add_edge(506, 237, w=6)
# S003S = 237,
G.add_edge(238, 510, w=6)
G.add_edge(509, 238, w=6)
# S004S = 238,
G.add_edge(239, 513, w=6)
G.add_edge(512, 239, w=6)
# S005S = 239,
G.add_edge(240, 516, w=6)
G.add_edge(515, 240, w=6)
# S006S = 240,
G.add_edge(241, 519, w=6)
G.add_edge(518, 241, w=6)
# S007S = 241,
G.add_edge(242, 522, w=6)
G.add_edge(521, 242, w=6)
# S008S = 242,

# T
G.add_edge(243, 525, w=6)
G.add_edge(524, 243, w=6)
# T001S = 243,
G.add_edge(244, 528, w=6)
G.add_edge(527, 244, w=6)
# T002S = 244,
G.add_edge(245, 531, w=6)
G.add_edge(530, 245, w=6)
# T003S = 245,
G.add_edge(246, 534, w=6)
G.add_edge(533, 246, w=6)
# T004S = 246,
G.add_edge(247, 537, w=6)
G.add_edge(536, 247, w=6)
# T005S = 247,
G.add_edge(248, 540, w=6)
G.add_edge(539, 248, w=6)
# T006S = 248,
G.add_edge(249, 543, w=6)
G.add_edge(542, 249, w=6)
# T007S = 249,
G.add_edge(250, 546, w=6)
G.add_edge(545, 250, w=6)
# T008S = 250,

# U
G.add_edge(251, 549, w=6)
G.add_edge(548, 251, w=6)
# U001S = 251,
G.add_edge(252, 552, w=6)
G.add_edge(551, 252, w=6)
# U002S = 252,
G.add_edge(253, 555, w=6)
G.add_edge(554, 253, w=6)
# U003S = 253,
G.add_edge(254, 558, w=6)
G.add_edge(557, 254, w=6)
# U004S = 254,
G.add_edge(255, 561, w=6)
G.add_edge(560, 255, w=6)
# U005S = 255,
G.add_edge(256, 564, w=6)
G.add_edge(563, 256, w=6)
# U006S = 256,
G.add_edge(257, 567, w=6)
G.add_edge(566, 257, w=6)
# U007S = 257,
G.add_edge(258, 570, w=6)
G.add_edge(569, 258, w=6)
# U008S = 258,

# V
G.add_edge(259, 573, w=6)
G.add_edge(572, 259, w=6)
# V001S = 259,
G.add_edge(260, 576, w=6)
G.add_edge(575, 260, w=6)
# V002S = 260,
G.add_edge(261, 579, w=6)
G.add_edge(578, 261, w=6)
# V003S = 261,
G.add_edge(262, 582, w=6)
G.add_edge(581, 262, w=6)
# V004S = 262,
G.add_edge(263, 585, w=6)
G.add_edge(584, 263, w=6)
# V005S = 263,
G.add_edge(264, 588, w=6)
G.add_edge(587, 264, w=6)
# V006S = 264,
G.add_edge(265, 591, w=6)
G.add_edge(590, 265, w=6)
# V007S = 265,
G.add_edge(266, 594, w=6)
G.add_edge(593, 266, w=6)
# V008S = 266,

# W
G.add_edge(267, 597, w=6)
G.add_edge(596, 267, w=6)
# W001S = 267,
G.add_edge(268, 600, w=6)
G.add_edge(599, 268, w=6)
# W002S = 268,
G.add_edge(269, 603, w=6)
G.add_edge(602, 269, w=6)
# W003S = 269,
G.add_edge(270, 606, w=6)
G.add_edge(605, 270, w=6)
# W004S = 270,
G.add_edge(271, 609, w=6)
G.add_edge(608, 271, w=6)
# W005S = 271,
G.add_edge(272, 612, w=6)
G.add_edge(611, 272, w=6)
# W006S = 272,
G.add_edge(273, 615, w=6)
G.add_edge(614, 273, w=6)
# W007S = 273,
G.add_edge(274, 618, w=6)
G.add_edge(617, 274, w=6)
# W008S = 274,

# X
G.add_edge(275, 621, w=6)
G.add_edge(620, 275, w=6)
# X001S = 275,
G.add_edge(276, 624, w=6)
G.add_edge(623, 276, w=6)
# X002S = 276,
G.add_edge(277, 627, w=6)
G.add_edge(626, 277, w=6)
# X003S = 277,
G.add_edge(278, 630, w=6)
G.add_edge(629, 278, w=6)
# X004S = 278,
G.add_edge(279, 633, w=6)
G.add_edge(632, 279, w=6)
# X005S = 279,
G.add_edge(280, 636, w=6)
G.add_edge(635, 280, w=6)
# X006S = 280,
G.add_edge(281, 639, w=6)
G.add_edge(638, 281, w=6)
# X007S = 281,
G.add_edge(282, 642, w=6)
G.add_edge(641, 282, w=6)
# X008S = 282,

# G
G.add_edge(283, 372, w=6)
G.add_edge(371, 283, w=6)
# G001S = 283,
G.add_edge(284, 369, w=6)
G.add_edge(368, 284, w=6)
# G002S = 284,
G.add_edge(285, 651, w=6)
G.add_edge(650, 285, w=6)
# G003S = 285,
G.add_edge(286, 654, w=6)
G.add_edge(653, 286, w=6)
# G004S = 286,
G.add_edge(287, 657, w=6)
G.add_edge(656, 287, w=6)
# G005S = 287,
G.add_edge(288, 660, w=6)
G.add_edge(659, 288, w=6)
# G006S = 288,

# H
G.add_edge(289, 396, w=6)
G.add_edge(395, 289, w=6)
# H001S = 289,
G.add_edge(290, 393, w=6)
G.add_edge(392, 290, w=6)
# H002S = 290,
G.add_edge(291, 669, w=6)
G.add_edge(668, 291, w=6)
# H003S = 291,
G.add_edge(292, 672, w=6)
G.add_edge(671, 292, w=6)
# H004S = 292,
G.add_edge(293, 675, w=6)
G.add_edge(674, 293, w=6)
# H005S = 293,
G.add_edge(294, 678, w=6)
G.add_edge(677, 294, w=6)
# H006S = 294,

# I
G.add_edge(295, 420, w=6)
G.add_edge(419, 295, w=6)
# I001S = 295,
G.add_edge(296, 417, w=6)
G.add_edge(416, 296, w=6)
# I002S = 296,
G.add_edge(297, 687, w=6)
G.add_edge(686, 297, w=6)
# I003S = 297,
G.add_edge(298, 690, w=6)
G.add_edge(689, 298, w=6)
# I004S = 298,
G.add_edge(299, 693, w=6)
G.add_edge(692, 299, w=6)
# I005S = 299,
G.add_edge(300, 696, w=6)
G.add_edge(695, 300, w=6)
# I006S = 300,

# J
G.add_edge(301, 444, w=6)
G.add_edge(443, 301, w=6)
# J001S = 301,
G.add_edge(302, 441, w=6)
G.add_edge(440, 302, w=6)
# J002S = 302,
G.add_edge(303, 705, w=6)
G.add_edge(704, 303, w=6)
# J003S = 303,
G.add_edge(304, 708, w=6)
G.add_edge(707, 304, w=6)
# J004S = 304,
G.add_edge(305, 711, w=6)
G.add_edge(710, 305, w=6)
# J005S = 305,
G.add_edge(306, 714, w=6)
G.add_edge(713, 306, w=6)
# J006S = 306,

# K
G.add_edge(307, 468, w=6)
G.add_edge(467, 307, w=6)
# K001S = 307,
G.add_edge(308, 465, w=6)
G.add_edge(464, 308, w=6)
# K002S = 308,
G.add_edge(309, 723, w=6)
G.add_edge(722, 309, w=6)
# K003S = 309,
G.add_edge(310, 726, w=6)
G.add_edge(725, 310, w=6)
# K004S = 310,
G.add_edge(311, 729, w=6)
G.add_edge(728, 311, w=6)
# K005S = 311,
G.add_edge(312, 732, w=6)
G.add_edge(731, 312, w=6)
# K006S = 312,

# L
G.add_edge(313, 492, w=6)
G.add_edge(491, 313, w=6)
# L001S = 313,
G.add_edge(314, 489, w=6)
G.add_edge(488, 314, w=6)
# L002S = 314,
G.add_edge(315, 741, w=6)
G.add_edge(740, 315, w=6)
# L003S = 315,
G.add_edge(316, 744, w=6)
G.add_edge(743, 316, w=6)
# L004S = 316,
G.add_edge(317, 747, w=6)
G.add_edge(746, 317, w=6)
# L005S = 317,
G.add_edge(318, 750, w=6)
G.add_edge(749, 318, w=6)
# L006S = 318,

# #M
G.add_edge(319, 768, w=6)
G.add_edge(767, 319, w=6)
    # M001S = 319,
G.add_edge(320, 753, w=6)
G.add_edge(752, 320, w=6)
    # M002S = 320,
G.add_edge(321, 756, w=6)
G.add_edge(755, 321, w=6)
    # M003S = 321,
G.add_edge(322, 504, w=6)
G.add_edge(503, 322, w=6)
    # M004S = 322,
G.add_edge(323, 501, w=6)
G.add_edge(500, 323, w=6)
    # M005S = 323,
G.add_edge(324, 765, w=6)
G.add_edge(764, 324, w=6)
    # M006S = 324,
# #N
G.add_edge(325, 786, w=6)
G.add_edge(785, 325, w=6)
    # N001S = 325,
G.add_edge(326, 770, w=6)
G.add_edge(769, 326, w=6)
    # N002S = 326,
G.add_edge(327, 775, w=6)
G.add_edge(774, 327, w=6)
    # N003S = 327,
G.add_edge(328, 529, w=6)
G.add_edge(528, 328, w=6)
    # N004S = 328,
G.add_edge(329, 524, w=6)
G.add_edge(523, 329, w=6)
    # N005S = 329,
G.add_edge(330, 782, w=6)
G.add_edge(781, 330, w=6)
    # N006S = 330,
# #O
G.add_edge(331, 804, w=6)
G.add_edge(803, 331, w=6)
    # O001S = 331,
G.add_edge(332, 788, w=6)
G.add_edge(787, 332, w=6)
    # O002S = 332,
G.add_edge(333, 792, w=6)
G.add_edge(791, 333, w=6)
    # O003S = 333,
G.add_edge(334, 552, w=6)
G.add_edge(551, 334, w=6)
    # O004S = 334,
G.add_edge(335, 548, w=6)
G.add_edge(547, 335, w=6)
    # O005S = 335,
G.add_edge(336, 801, w=6)
G.add_edge(800, 336, w=6)
    # O006S = 336,
# #P
G.add_edge(337, 822, w=6)
G.add_edge(821, 337, w=6)
    # P001S = 337,
G.add_edge(338, 806, w=6)
G.add_edge(805, 338, w=6)
    # P002S = 338,
G.add_edge(339, 810, w=6)
G.add_edge(809, 339, w=6)
    # P003S = 339,
G.add_edge(340, 575, w=6)
G.add_edge(574, 340, w=6)
    # P004S = 340,
G.add_edge(341, 572, w=6)
G.add_edge(571, 341, w=6)
    # P005S = 341,
G.add_edge(342, 819, w=6)
G.add_edge(818, 342, w=6)
    # P006S = 342,
# #Q
G.add_edge(343, 840, w=6)
G.add_edge(839, 343, w=6)
    # Q001S = 343,
G.add_edge(344, 824, w=6)
G.add_edge(823, 344, w=6)
    # Q002S = 344,
G.add_edge(345, 828, w=6)
G.add_edge(827, 345, w=6)
    # Q003S = 345,
G.add_edge(346, 600, w=6)
G.add_edge(599, 346, w=6)
    # Q004S = 346,
G.add_edge(347, 596, w=6)
G.add_edge(595, 347, w=6)
    # Q005S = 347,
G.add_edge(348, 837, w=6)
G.add_edge(836, 348, w=6)
    # Q006S = 348,
# #R
G.add_edge(349, 858, w=6)
G.add_edge(857, 349, w=6)
    # R001S = 349,
G.add_edge(350, 842, w=6)
G.add_edge(841, 350, w=6)
    # R002S = 350,
G.add_edge(351, 846, w=6)
G.add_edge(845, 351, w=6)
    # R003S = 351,
G.add_edge(352, 624, w=6)
G.add_edge(623, 352, w=6)
    # R004S = 352,
G.add_edge(353, 620, w=6)
G.add_edge(619, 353, w=6)
    # R005S = 353,
G.add_edge(354, 855, w=6)
G.add_edge(854, 354, w=6)
    # R006S = 354,


def listToString(s, pos, flat):
    # initialize an empty string 
    str1 = "{"

    # traverse in the string   
    for ele in range(len(s)):
        try:
            val = G[pos][ele]['w']
        except Exception as e:
            val = -1

        if ele != len(s) - 1:
            str1 += str(val) + ", "
        else:
            str1 += str(val)

            # return string
    str1 += "}"
    if flat:
        str1 += ", "
    return str1


A = nx.adjacency_matrix(G)
temp = A.todense()

a = [[0 for j in range(0, len(temp))] for i in range(0, len(temp))]

f = open("graph.h", "w")
f.write("int threadville_graph[" + str(len(temp)) + "][" + str(len(temp)) + "] =  {")

# iterate through rows
for i in range(len(temp)):
    # iterate through columns
    for j in range(len(temp[0])):
        a[j][i] = temp[i][j]

for i in range(len(a)):
    if i + 1 < len(a):
        text = listToString(a[i], i, True)
        f.write(text)
        f.write("\n")
    else:
        text = listToString(a[i], i, False)
        f.write(text + "};\n")
f.close()
