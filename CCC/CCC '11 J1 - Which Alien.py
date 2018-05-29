antenna = int(input())
eyes = int(input())
TM = True
VS = True
GM = True
if antenna < 3:
    TM = False
if antenna > 6:
    VS = False
if antenna > 2:
    GM = False
if eyes > 4:
    TM = False
if eyes < 2:
    VS = False
if eyes > 3:
    GM = False

if TM:
    print("TroyMartian")
if VS:
    print("VladSaturnian")
if GM:
    print("GraemeMercurian")