#ifndef PROYECTO3_UTILS_H
#define PROYECTO3_UTILS_H

#include <stdlib.h>
#include "lista_enlazada.h"
#include "lista_enlazada_carros.h"

#define MAX_ID_NUMBER 984

void *create_shared_memory(size_t);

pthread_condattr_t get_conditional_attribute();

pthread_mutexattr_t *get_mutex_attributes();

pthread_mutex_t *get_mutex(pthread_mutexattr_t *);

typedef enum HighwayIds {
    // FROM Z TO Y 1
    H001H = 1,
    H002H = 2,
    H003H = 3,
    H004H = 4,
    H005H = 5,
    H006H = 6,
    H007H = 7,
    H008H = 8,
    H009H = 9,
    H010H = 10,
    H011H = 11,
    H012H = 12,
    H013H = 13,
    H014H = 14,
    H015H = 15,
    H016H = 16,
    H017H = 17,
    H018H = 18,
    H019H = 19,
    H020H = 20,
    H021H = 21,
    H022H = 22,
    H023H = 23,
    H024H = 24,
    H025H = 25,
    H026H = 26,
    H027H = 27,
    H028H = 28,
    H029H = 29,
    H030H = 30,
    H031H = 31,
    H032H = 32,
    H033H = 33,
    H034H = 34,
    H035H = 35,
    H036H = 36,
    // FROM Z TO Y 2
    H037H = 37,
    H038H = 38,
    H039H = 39,
    H040H = 40,
    H041H = 41,
    H042H = 42,
    H043H = 43,
    H044H = 44,
    H045H = 45,
    H046H = 46,
    H047H = 47,
    H048H = 48,
    H049H = 49,
    H050H = 50,
    H051H = 51,
    H052H = 52,
    H053H = 53,
    H054H = 54,
    H055H = 55,
    H056H = 56,
    H057H = 57,
    H058H = 58,
    H059H = 59,
    H060H = 60,
    H061H = 61,
    H062H = 62,
    H063H = 63,
    H064H = 64,
    H065H = 65,
    H066H = 66,
    H067H = 67,
    H068H = 68,
    H069H = 69,
    H070H = 70,
    H071H = 71,
    H072H = 72,
    // FROM Y TO Z 1
    H073H = 73,
    H074H = 74,
    H075H = 75,
    H076H = 76,
    H077H = 77,
    H078H = 78,
    H079H = 79,
    H080H = 80,
    H081H = 81,
    H082H = 82,
    H083H = 83,
    H084H = 84,
    H085H = 85,
    H086H = 86,
    H087H = 87,
    H088H = 88,
    H089H = 89,
    H090H = 90,
    H091H = 91,
    H092H = 92,
    H093H = 93,
    H094H = 94,
    H095H = 95,
    H096H = 96,
    H097H = 97,
    H098H = 98,
    H099H = 99,
    H100H = 100,
    H101H = 101,
    H102H = 102,
    H103H = 103,
    H104H = 104,
    H105H = 105,
    H106H = 106,
    H107H = 107,
    H108H = 108,
    // FROM Y TO Z 2
    H109H = 109,
    H110H = 110,
    H111H = 111,
    H112H = 112,
    H113H = 113,
    H114H = 114,
    H115H = 115,
    H116H = 116,
    H117H = 117,
    H118H = 118,
    H119H = 119,
    H120H = 120,
    H121H = 121,
    H122H = 122,
    H123H = 123,
    H124H = 124,
    H125H = 125,
    H126H = 126,
    H127H = 127,
    H128H = 128,
    H129H = 129,
    H130H = 130,
    H131H = 131,
    H132H = 132,
    H133H = 133,
    H134H = 134,
    H135H = 135,
    H136H = 136,
    H137H = 137,
    H138H = 138,
    H139H = 139,
    H140H = 140,
    H141H = 141,
    H142H = 142,
    H143H = 143,
    H144H = 144,
} HighwaysIds;

typedef enum BridgeIds {
    // Larry
    B001B = 145,
    B002B = 146,
    B003B = 147,
    B004B = 148,
    B005B = 149,
    B006B = 150,
    BU01B = 955,
    BU02B = 956,
    BU03B = 957,
    BU04B = 958,
    BU05B = 959,
    BU06B = 960,
    // Curly
    B007B = 151,
    B008B = 152,
    B009B = 153,
    B010B = 154,
    B011B = 155,
    B012B = 156,
    BU07B = 961,
    BU08B = 962,
    BU09B = 963,
    BU10B = 964,
    BU11B = 965,
    BU12B = 966,
    // Moe
    B013B = 157,
    B014B = 158,
    B015B = 159,
    B016B = 160,
    B017B = 161,
    B018B = 162,
    BU13B = 967,
    BU14B = 968,
    BU15B = 969,
    BU16B = 970,
    BU17B = 971,
    BU18B = 972,
    // Shemp
    B019B = 163,
    B020B = 164,
    B021B = 165,
    B022B = 166,
    B023B = 167,
    B024B = 168,
    BU19B = 973,
    BU20B = 974,
    BU21B = 975,
    BU22B = 976,
    BU23B = 977,
    BU24B = 978,
    // Joe
    B025B = 169,
    B026B = 170,
    B027B = 171,
    B028B = 172,
    B029B = 173,
    B030B = 174,
    BU25B = 979,
    BU26B = 980,
    BU27B = 981,
    BU28B = 982,
    BU29B = 983,
    BU30B = 984,
} BridgeIds;

typedef enum RoundaboutIds {
    Y001R = 175,
    Y002R = 176,
    Y003R = 177,
    Y004R = 178,
    Y005R = 179,
    Y006R = 180,
    Z001R = 181,
    Z002R = 182,
    Z003R = 183,
    Z004R = 184,
    Z005R = 185,
    Z006R = 186,
} RoundaboutIds;

typedef enum StopIds {
    A001S = 187,
    A002S = 188,
    A003S = 189,
    A004S = 190,
    A005S = 191,
    A006S = 192,
    A007S = 193,
    A008S = 194,
    B001S = 195,
    B002S = 196,
    B003S = 197,
    B004S = 198,
    B005S = 199,
    B006S = 200,
    B007S = 201,
    B008S = 202,
    C001S = 203,
    C002S = 204,
    C003S = 205,
    C004S = 206,
    C005S = 207,
    C006S = 208,
    C007S = 209,
    C008S = 210,
    D001S = 211,
    D002S = 212,
    D003S = 213,
    D004S = 214,
    D005S = 215,
    D006S = 216,
    D007S = 217,
    D008S = 218,
    E001S = 219,
    E002S = 220,
    E003S = 221,
    E004S = 222,
    E005S = 223,
    E006S = 224,
    E007S = 225,
    E008S = 226,
    F001S = 227,
    F002S = 228,
    F003S = 229,
    F004S = 230,
    F005S = 231,
    F006S = 232,
    F007S = 233,
    F008S = 234,
    S001S = 235,
    S002S = 236,
    S003S = 237,
    S004S = 238,
    S005S = 239,
    S006S = 240,
    S007S = 241,
    S008S = 242,
    T001S = 243,
    T002S = 244,
    T003S = 245,
    T004S = 246,
    T005S = 247,
    T006S = 248,
    T007S = 249,
    T008S = 250,
    U001S = 251,
    U002S = 252,
    U003S = 253,
    U004S = 254,
    U005S = 255,
    U006S = 256,
    U007S = 257,
    U008S = 258,
    V001S = 259,
    V002S = 260,
    V003S = 261,
    V004S = 262,
    V005S = 263,
    V006S = 264,
    V007S = 265,
    V008S = 266,
    W001S = 267,
    W002S = 268,
    W003S = 269,
    W004S = 270,
    W005S = 271,
    W006S = 272,
    W007S = 273,
    W008S = 274,
    X001S = 275,
    X002S = 276,
    X003S = 277,
    X004S = 278,
    X005S = 279,
    X006S = 280,
    X007S = 281,
    X008S = 282,
    G001S = 283,
    G002S = 284,
    G003S = 285,
    G004S = 286,
    G005S = 287,
    G006S = 288,
    H001S = 289,
    H002S = 290,
    H003S = 291,
    H004S = 292,
    H005S = 293,
    H006S = 294,
    I001S = 295,
    I002S = 296,
    I003S = 297,
    I004S = 298,
    I005S = 299,
    I006S = 300,
    J001S = 301,
    J002S = 302,
    J003S = 303,
    J004S = 304,
    J005S = 305,
    J006S = 306,
    K001S = 307,
    K002S = 308,
    K003S = 309,
    K004S = 310,
    K005S = 311,
    K006S = 312,
    L001S = 313,
    L002S = 314,
    L003S = 315,
    L004S = 316,
    L005S = 317,
    L006S = 318,
    M001S = 319,
    M002S = 320,
    M003S = 321,
    M004S = 322,
    M005S = 323,
    M006S = 324,
    N001S = 325,
    N002S = 326,
    N003S = 327,
    N004S = 328,
    N005S = 329,
    N006S = 330,
    O001S = 331,
    O002S = 332,
    O003S = 333,
    O004S = 334,
    O005S = 335,
    O006S = 336,
    P001S = 337,
    P002S = 338,
    P003S = 339,
    P004S = 340,
    P005S = 341,
    P006S = 342,
    Q001S = 343,
    Q002S = 344,
    Q003S = 345,
    Q004S = 346,
    Q005S = 347,
    Q006S = 348,
    R001S = 349,
    R002S = 350,
    R003S = 351,
    R004S = 352,
    R005S = 353,
    R006S = 354,
} StopIds;

typedef enum StreetIds {
    A001P = 355,
    A002P = 356,
    A003P = 357,
    A004P = 358,
    A005P = 359,
    A006P = 360,
    A007P = 361,
    A008P = 362,
    A009P = 363,
    A010P = 364,
    A011P = 365,
    A012P = 366,
    A013P = 367,
    A014P = 368,
    A015P = 369,
    A016P = 370,
    A017P = 371,
    A018P = 372,
    A019P = 373,
    A020P = 374,
    A021P = 375,
    A022P = 376,
    A023P = 377,
    A024P = 378,
    B001P = 379,
    B002P = 380,
    B003P = 381,
    B004P = 382,
    B005P = 383,
    B006P = 384,
    B007P = 385,
    B008P = 386,
    B009P = 387,
    B010P = 388,
    B011P = 389,
    B012P = 390,
    B013P = 391,
    B014P = 392,
    B015P = 393,
    B016P = 394,
    B017P = 395,
    B018P = 396,
    B019P = 397,
    B020P = 398,
    B021P = 399,
    B022P = 400,
    B023P = 401,
    B024P = 402,
    C001P = 403,
    C002P = 404,
    C003P = 405,
    C004P = 406,
    C005P = 407,
    C006P = 408,
    C007P = 409,
    C008P = 410,
    C009P = 411,
    C010P = 412,
    C011P = 413,
    C012P = 414,
    C013P = 415,
    C014P = 416,
    C015P = 417,
    C016P = 418,
    C017P = 419,
    C018P = 420,
    C019P = 421,
    C020P = 422,
    C021P = 423,
    C022P = 424,
    C023P = 425,
    C024P = 426,
    D001P = 427,
    D002P = 428,
    D003P = 429,
    D004P = 430,
    D005P = 431,
    D006P = 432,
    D007P = 433,
    D008P = 434,
    D009P = 435,
    D010P = 436,
    D011P = 437,
    D012P = 438,
    D013P = 439,
    D014P = 440,
    D015P = 441,
    D016P = 442,
    D017P = 443,
    D018P = 444,
    D019P = 445,
    D020P = 446,
    D021P = 447,
    D022P = 448,
    D023P = 449,
    D024P = 450,
    E001P = 451,
    E002P = 452,
    E003P = 453,
    E004P = 454,
    E005P = 455,
    E006P = 456,
    E007P = 457,
    E008P = 458,
    E009P = 459,
    E010P = 460,
    E011P = 461,
    E012P = 462,
    E013P = 463,
    E014P = 464,
    E015P = 465,
    E016P = 466,
    E017P = 467,
    E018P = 468,
    E019P = 469,
    E020P = 470,
    E021P = 471,
    E022P = 472,
    E023P = 473,
    E024P = 474,
    F001P = 475,
    F002P = 476,
    F003P = 477,
    F004P = 478,
    F005P = 479,
    F006P = 480,
    F007P = 481,
    F008P = 482,
    F009P = 483,
    F010P = 484,
    F011P = 485,
    F012P = 486,
    F013P = 487,
    F014P = 488,
    F015P = 489,
    F016P = 490,
    F017P = 491,
    F018P = 492,
    F019P = 493,
    F020P = 494,
    F021P = 495,
    F022P = 496,
    F023P = 497,
    F024P = 498,
    S006P = 504,
    S005P = 503,
    S004P = 502,
    S003P = 501,
    S002P = 500,
    S001P = 499,
    S007P = 505,
    S008P = 506,
    S009P = 507,
    S010P = 508,
    S011P = 509,
    S012P = 510,
    S013P = 511,
    S014P = 512,
    S015P = 513,
    S016P = 514,
    S017P = 515,
    S018P = 516,
    S019P = 517,
    S020P = 518,
    S021P = 519,
    S022P = 520,
    S023P = 521,
    S024P = 522,
    T006P = 523,
    T005P = 524,
    T004P = 525,
    T003P = 526,
    T002P = 527,
    T001P = 528,
    T007P = 529,
    T008P = 530,
    T009P = 531,
    T010P = 532,
    T011P = 533,
    T012P = 534,
    T013P = 535,
    T014P = 536,
    T015P = 537,
    T016P = 538,
    T017P = 539,
    T018P = 540,
    T019P = 541,
    T020P = 542,
    T021P = 543,
    T022P = 544,
    T023P = 545,
    T024P = 546,
    U006P = 547,
    U005P = 548,
    U004P = 549,
    U003P = 550,
    U002P = 551,
    U001P = 552,
    U007P = 553,
    U008P = 554,
    U009P = 555,
    U010P = 556,
    U011P = 557,
    U012P = 558,
    U013P = 559,
    U014P = 560,
    U015P = 561,
    U016P = 562,
    U017P = 563,
    U018P = 564,
    U019P = 565,
    U020P = 566,
    U021P = 567,
    U022P = 568,
    U023P = 569,
    U024P = 570,
    V006P = 571,
    V005P = 572,
    V004P = 573,
    V003P = 574,
    V002P = 575,
    V001P = 576,
    V007P = 577,
    V008P = 578,
    V009P = 579,
    V010P = 580,
    V011P = 581,
    V012P = 582,
    V013P = 583,
    V014P = 584,
    V015P = 585,
    V016P = 586,
    V017P = 587,
    V018P = 588,
    V019P = 589,
    V020P = 590,
    V021P = 591,
    V022P = 592,
    V023P = 593,
    V024P = 594,
    W006P = 595,
    W005P = 596,
    W004P = 597,
    W003P = 598,
    W002P = 599,
    W001P = 600,
    W007P = 601,
    W008P = 602,
    W009P = 603,
    W010P = 604,
    W011P = 605,
    W012P = 606,
    W013P = 607,
    W014P = 608,
    W015P = 609,
    W016P = 610,
    W017P = 611,
    W018P = 612,
    W019P = 613,
    W020P = 614,
    W021P = 615,
    W022P = 616,
    W023P = 617,
    W024P = 618,
    X006P = 619,
    X005P = 620,
    X004P = 621,
    X003P = 622,
    X002P = 623,
    X001P = 624,
    X007P = 625,
    X008P = 626,
    X009P = 627,
    X010P = 628,
    X011P = 629,
    X012P = 630,
    X013P = 631,
    X014P = 632,
    X015P = 633,
    X016P = 634,
    X017P = 635,
    X018P = 636,
    X019P = 637,
    X020P = 638,
    X021P = 639,
    X022P = 640,
    X023P = 641,
    X024P = 642,
    G001P = 367,
    G002P = 368,
    G003P = 369,
    G004P = 370,
    G005P = 371,
    G006P = 372,
    G007P = 649,
    G008P = 650,
    G009P = 651,
    G010P = 652,
    G011P = 653,
    G012P = 654,
    G013P = 655,
    G014P = 656,
    G015P = 657,
    G016P = 658,
    G017P = 659,
    G018P = 660,
    H001P = 391,
    H002P = 392,
    H003P = 393,
    H004P = 394,
    H005P = 395,
    H006P = 396,
    H007P = 667,
    H008P = 668,
    H009P = 669,
    H010P = 670,
    H011P = 671,
    H012P = 672,
    H013P = 673,
    H014P = 674,
    H015P = 675,
    H016P = 676,
    H017P = 677,
    H018P = 678,
    I001P = 415,
    I002P = 416,
    I003P = 417,
    I004P = 418,
    I005P = 419,
    I006P = 420,
    I007P = 685,
    I008P = 686,
    I009P = 687,
    I010P = 688,
    I011P = 689,
    I012P = 690,
    I013P = 691,
    I014P = 692,
    I015P = 693,
    I016P = 694,
    I017P = 695,
    I018P = 696,
    J001P = 439,
    J002P = 440,
    J003P = 441,
    J004P = 442,
    J005P = 443,
    J006P = 444,
    J007P = 703,
    J008P = 704,
    J009P = 705,
    J010P = 706,
    J011P = 707,
    J012P = 708,
    J013P = 709,
    J014P = 710,
    J015P = 711,
    J016P = 712,
    J017P = 713,
    J018P = 714,
    K001P = 463,
    K002P = 464,
    K003P = 465,
    K004P = 466,
    K005P = 467,
    K006P = 468,
    K007P = 721,
    K008P = 722,
    K009P = 723,
    K010P = 724,
    K011P = 725,
    K012P = 726,
    K013P = 727,
    K014P = 728,
    K015P = 729,
    K016P = 730,
    K017P = 731,
    K018P = 732,
    L001P = 487,
    L002P = 488,
    L003P = 489,
    L004P = 490,
    L005P = 491,
    L006P = 492,
    L007P = 739,
    L008P = 740,
    L009P = 741,
    L010P = 742,
    L011P = 743,
    L012P = 744,
    L013P = 745,
    L014P = 746,
    L015P = 747,
    L016P = 748,
    L017P = 749,
    L018P = 750,
    M001P = 751,
    M002P = 752,
    M003P = 753,
    M004P = 754,
    M005P = 755,
    M006P = 756,
    M012P = 499,
    M011P = 500,
    M010P = 501,
    M009P = 502,
    M008P = 503,
    M007P = 504,
    M013P = 763,
    M014P = 764,
    M015P = 765,
    M016P = 766,
    M017P = 767,
    M018P = 768,
    N001P = 769,
    N002P = 770,
    N003P = 771,
    N004P = 772,
    N005P = 773,
    N006P = 774,
    N012P = 523,
    N011P = 524,
    N010P = 525,
    N009P = 526,
    N008P = 527,
    N007P = 528,
    N013P = 781,
    N014P = 782,
    N015P = 783,
    N016P = 784,
    N017P = 785,
    N018P = 786,
    O001P = 787,
    O002P = 788,
    O003P = 789,
    O004P = 790,
    O005P = 791,
    O006P = 792,
    O012P = 547,
    O011P = 548,
    O010P = 549,
    O009P = 550,
    O008P = 551,
    O007P = 552,
    O013P = 799,
    O014P = 800,
    O015P = 801,
    O016P = 802,
    O017P = 803,
    O018P = 804,
    P001P = 805,
    P002P = 806,
    P003P = 807,
    P004P = 808,
    P005P = 809,
    P006P = 810,
    P012P = 571,
    P011P = 572,
    P010P = 573,
    P009P = 574,
    P008P = 575,
    P007P = 576,
    P013P = 817,
    P014P = 818,
    P015P = 819,
    P016P = 820,
    P017P = 821,
    P018P = 822,
    Q001P = 823,
    Q002P = 824,
    Q003P = 825,
    Q004P = 826,
    Q005P = 827,
    Q006P = 828,
    Q012P = 595,
    Q011P = 596,
    Q010P = 597,
    Q009P = 598,
    Q008P = 599,
    Q007P = 600,
    Q013P = 835,
    Q014P = 836,
    Q015P = 837,
    Q016P = 838,
    Q017P = 839,
    Q018P = 840,
    R001P = 841,
    R002P = 842,
    R003P = 843,
    R004P = 844,
    R005P = 845,
    R006P = 846,
    R012P = 619,
    R011P = 620,
    R010P = 621,
    R009P = 622,
    R008P = 623,
    R007P = 624,
    R013P = 853,
    R014P = 854,
    R015P = 855,
    R016P = 856,
    R017P = 857,
    R018P = 858,
} StreetIds;

typedef enum CornersIds {
    A001C = 859,
    A002C = 860,
    A003C = 861,
    A004C = 862,
    B001C = 863,
    B002C = 864,
    B003C = 865,
    B004C = 866,
    C001C = 867,
    C002C = 868,
    C003C = 869,
    C004C = 870,
    D001C = 871,
    D002C = 872,
    D003C = 873,
    D004C = 874,
    E001C = 875,
    E002C = 876,
    E003C = 877,
    E004C = 878,
    F001C = 879,
    F002C = 880,
    F003C = 881,
    F004C = 882,
    G001C = 862,
    G002C = 861,
    H001C = 866,
    H002C = 865,
    I001C = 870,
    I002C = 869,
    J001C = 874,
    J002C = 873,
    K001C = 878,
    K002C = 877,
    L001C = 882,
    L002C = 881,
    M001C = 909,
    M002C = 910,
    N001C = 913,
    N002C = 914,
    O001C = 917,
    O002C = 918,
    P001C = 921,
    P002C = 922,
    Q001C = 925,
    Q002C = 926,
    R001C = 929,
    R002C = 930,
    S001C = 910,
    S002C = 909,
    S003C = 933,
    S004C = 934,
    T001C = 914,
    T002C = 913,
    T003C = 937,
    T004C = 938,
    U001C = 918,
    U002C = 917,
    U003C = 941,
    U004C = 942,
    V001C = 922,
    V002C = 921,
    V003C = 945,
    V004C = 946,
    W001C = 926,
    W002C = 925,
    W003C = 949,
    W004C = 950,
    X001C = 930,
    X002C = 929,
    X003C = 953,
    X004C = 954
} CornersIds;

#endif //PROYECTO3_UTILS_H
