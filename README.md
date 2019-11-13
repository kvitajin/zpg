# ZPG - Základy počítačové grafiky

## Cíle předmětu vyjádřené dosaženými dovednostmi a kompetencemi
Cílem předmětu je seznámit posluchače se základy počítačové grafiky. Získat přehled v oblasti základních principů 2D a zejména 3D počítačové grafiky. Posluchači se během semestru seznámí se základním principem grafické karty a zobrazovacího řetězce. Postupně budou prezentovány základními algoritmy používanými v počítačové grafice. Výsledkem bude projekt, na kterém studenti demonstrují získané znalosti, který bude umožňovat zobrazovat 3D scénu, pohybovat kamerou, objekty, nastavovat světla, barvy, textury, doplnit scénu o stíny, průhlednost, normál mapy apod.
## Vyučovací metody

Přednášky <br/>
Semináře <br/>
Individuální konzultace<br/>
Cvičení (v učebně)<br/>
Projekt<br/>
## Anotace
Předmět si klade za cíl seznámit posluchače se základními možnostmi moderních grafických karet a s jejich použitím v oblasti počítačové grafiky. V předmětu jsou posluchači seznamováni zejména s grafickou knihovnou OpenGL. Důraz je kladen zejména na předvedení standartního zobrazovacího řetězce (rendering pipeline) v moderním OpenGL (verze 3.3++). 

## Povinná literatura:
Němec: Sylaby přednášek Základy počítačové grafiky.<br/>
Sojka E., Němec M., Fabián T.: Matematické základy počítačové grafiky, http://mi21.vsb.cz.<br/>
## Doporučená literatura:
J. Žára, B. Beneš, J. Sochor, P. Felkel:Moderní počítačová grafika (2. vydání),Computer Press, 2005, ISBN 80-251-0454-0.<br/>
J. Sochor, J. Žára: Algoritmy počítačové grafiky. Skripta ČVUT Praha 1993.<br/>
D. Martišek, Matematické principy grafických systémů, Littera, 2002.<br/>
## Forma způsobu ověření studijních výsledků a další požadavky na studenta
Vypracovaní souboru úloh zadaných na cvičení. Vypracování projektu.
## E-learning
## Další požadavky na studenta
Další požadavky na studenta nejsou kladeny.
## Prerekvizity

Předmět nemá žádné prerekvizity.
## Korekvizity

Předmět nemá žádné korekvizity.
## Osnova předmětu
Přednášky:<br/>
1. Úvod, rastrový a vektorový popis (bod, vektor, přímka, souřadný systém), generování objektů v rastru (interpolace).
2. Grafický hardware, funkční schéma (rendering pipeline). Úvod do standardního zobrazovacího řetězce (OpenGL).
3. Reprezentace 3D objektů (polygonální, CSG, procedurální reprezentace). Topologie. Formáty (OBJ apod.).
4. Transformace v PG (translace, rotace, změna měřítka), homogenní souřadný systém.
5. Promítání (perspektiva vs. ortogonální promítání), kamera, ořezání (clipping), rasterizace.
6. Barva, lidské oko, barevné modely, světlo (bodové, reflektor, směrové, plošné). Míchání barev (blending).
7. Osvětlení, intenzita osvětlení, lokální osvětlovací modely (Lambert, Phong), globální osvětlovací modely, BRDF, radiozita, ray-tracing, ambient occlusion, stínování.
8. Textury v OpenGL, texturovací jednotky, texel. UV mapování.
9. Řešení viditelnosti (z-buffer, malířův algoritmus). Skybox, skydome.
10. Optická iluze nerovnosti (bump mapping, normal mapping). Displacement mapping.
11. Stíny v počítačové grafice. Shadow mapping.
12. Úvod do křivek a ploch (Bézierova křivka a plocha).

Na cvičeních budou probírána témata teoreticky vysvětlená na přednáškách.<br/>
Cvičení:
1. Opakování matematika, matice apod. Projekt C++, link knihoven.
2. Úvod do moderního OpenGL. Struktura projektu.
3. Objekty v OpenGL, VBO, IBO, glDrawElements, glDrawArrays.
4. Pohledové a projekční transformace (MVP).
5. Shadery (vertex, fragment).
6. Phongův osvětlovací model.
7. Načtení textury (OpenCV), uv-mapování.
8. Viditelnost, skybox, skydome.
9. Normal mapping.
10. Výpočet stínů, Stínové mapy.
11. Pohyb pro křivce.
12. 3D tisk.
