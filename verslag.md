# Verslag eindopdracht 6V
### gemaakt door *Sanne Versluis*, *Olivier Drees*, *Bo Goedhart*, *Arvind Sanchit*, *Precia Juwono*

---

## Inleiding
Wij hebben met een groepje van vijf een knikkerbaan gebouwd. Samen hebben we nagedacht over het ontwerp ervan en het bevat uiteindelijk best een aantal verschillende features, die we allemaal wel leuk vonden om in onze knikkerbaan te verwerken.  


## Features
Beschrijf hier de eigenschappen van jullie knikkerbaan (gebruik gerust plaatjes) kijk in map fotos naar KnikkerBaan.png . De eerste paar zijn voorgegeven:

### feature 1: Opvangen van knikkers
De knikkerbaan kan knikkers bovenin correct opvangen. De binnenkomende knikkers worden geteld en een poortje bepaalt of knikkers worden doorrollen of worden tegengehouden.

### feature 2: Doorgeven van gegevens aan server
De knikkerbaan zendt de hoeveelheid getelde knikkers naar een server die de gegevens opslaat in een database. Deze server kan per 'run' (d.w.z. een nieuwe keer aangaan) gegevens bijhouden.

### feature 3: Widget wisselt info uit met knikkerbaan
In de browser kan met een URL een widget worden geladen. Deze geeft de knikkerbaan schematisch weer in een frame van 800x400px. De getelde knikkers en duur dat de poort openstaat worden hierin getoond. De duur dat de poort openstaat kan hierin worden veranderd. De knikkerbaan kan deze wachttijd van de server ontvangen en zijn werking erop aanpassen.

### feature 4: Draairad 
In onze knikkerbaan hebben wij de knikkers die vanuit de opvangtrechter komen, in een rad te laten draaien. Het rad draait met en servo die 360 graden kan draaien. 

### feature 5: Kleurendoos en LED
Nadat de knikkers door het rad zijn geweest, gaan ze door een kleurendoosje heen. Hierin zit de kleurensensor verwerkt. ZOdra de kleurensensor de knikker heeft gescanned wordt de kleur van de knikker weergegeven op de LED ernaast. De kleurendoos kan de knikkers twee verschillende kanten op laten gaan. Dit wordt gedaan door het onderste plankje van de kleurendoos, die is verbonden aan een servo.

### feature 6: Looping
Op het einde van de rechter baan is er een looping in verwerkt. Dit hebben wij gedaan met een solenoid die de knikkers ophoog schieten. De rest van de onderdelen van de looping is met een 3D-printer uitgeprint. 


## Evaluaties van scrumplanningen:

### week 43
De eerste week van de start van het project hebben we eerst goed nagedacht hoe we het eruit wilden laten zien.

### week 44
In deze week hebben we ons plan wat meer uigewerkt en we begonnen ook met het schetsen ervan.

### week 45
Ons plan voor de knikkerbaan was duidelijk, dus we konden beginnen met het schetsen op de plank. 

### week 48 
De schets op de plank moest afgemaakt worden. Er was ook een begin gemaakt aan de code. 

### week 49
Verder gewerkt aan de schets op de plank en kleine aanpassingen in de baan gemaakt. 

### week 50 
Er is veel gewerkt aan de code voor de knikkerbaan. De schets op de plank was af. 

### week 2
Begonnen met de onderdelen van de knikerbaan uit te printen op de 3D-printer en het snijden van de onderdelen van de baan. 

### week 6 
Veel in het HT-lokaal gewerkt voor het zagen en lijmen van de onderdelen van de knikkerbaan. Verder gegaan met de code. 

### week 7 
De plank hebben we zwart geverfd en we hebben de knikkerbaan in elkaar gezet. Veel features waren al afgerond.

### week 8
De kleinde dingen die in de baan ontbraken hebben we op de baan geplakt en de code die misten zijn afgerond. 



## Technische verantwoording
Geef hier bijvoorbeeld de volgene informatie, maar voel je vrij er informatie aan toe te voegen.

De Arduino werkt op de volgende manier:
De arduino stuurt verschillende poortjes en sensoren aan met behulp van classes. Verder hebben we zelf classes gemaakt voor de wissel en de solenoid. De code van de RGB sensor het het ledje waar hij mee samenwerkt in de main tab gezet, aangezien dit erg lastig is om een class van te maken. Ook de code van het rad staat in de main, omdat deze code er kort en simpel was.

De knikkerbaan en de widget wisselen de volgende data met elkaar uit:
Op de widget kan de wachttijd van het eerste poortje handmatig worden ingesteld en deze informatie haalt de arduino op uit de database. Ook kan er op de widget gekozen worden of de wissel in het kleuren doosje naar links of rehts beweegt dit voert de arduino dan uit. Het aantal waargenomen knikkers bij het eerste poortje wordt door de arduino doorgestuurd en daardoor komt deze via de data base op de widget.

In de database hebben we een kolom toegevoegd voor de wachttijd op de widget wordt ingevuld en een kolom voor of er op de widget links of rechts is gekozen bij de wissel.

Uitdagingen die we tegenkwamen:
Dat de techniek niet altijd meewerkt en dat er veel tijd in kan gaan zitten om een erg klein probleem op te lossen.

## Reflectie op opdracht
#### --Precia--
Ik vond deze opdracht best lastig aangezien we ineens al onze kennis over programmeren bij elkaar moesten gooien. Daarnaast heb ik er wel veel van geleerd en ik vond het ook wel leuk hoe wij met een wat groter groepje toch hebben kunnen overleggen hoe we het eruit wilde laten zien. 

#### --Sanne--
Ik vond het een erg leuke, maar ook lastige opdracht. Het was erg leuk omdat we zoveel creatieve vrijheid hadden. Ik vond het erg lastig, omdat we bij erg veel onderdelen tegen problemen aan konden lopen waar we soms echt hulp bij nodig hadden en corona maakte dit soms erg lastig, waardoor vragen soms erg lang moesten wachten. Ik vind het daarom ook erg jammer dat we bijvoorbeeld de solenoid niet hard genoeg kunnen afschieten om de looping goed door te komen. Ik denk dat we zonder de problemen vanwege corona toch nog meer uit het project hadden kunnen halen dan nu, maar alsnog vond ik het erg leuk om een beetje alle dingen die we de afgelopen jaren bij informatica hebben geleerd te combineren.

#### --Olivier--
Ik vond het een hele leerzame en leuke opdracht. Ik heb het zelden echt leuk tijdens een PO voor school, maar dit PO was wat dat betreft absoluut een uitzondering. Natuurlijk ging niet alles zoals verwacht, maar van dat soort tegenslagen kan je leren zodat je deze fouten niet nog een keer maakt. Al met al denk ik dat dit PO een groot succes was, zowel op het gebied van leerzaamheid als samenwerking.

#### --Arvind--
Ik vond het een leuke opdracht waar ook veel creativiteit bij kwam kijken. Desondanks het een leuke opdracht was was het ook een erg lastige opdracht en hebben we veel problemen gehad. Door corona hadden we nog wat extra problemen waardoor wij misschien beperkt waren in wat we echt konden doen maar toch denk ik dat we uiteindelijk toch iets moois hebben neer gezet.

#### --Bo--
Ik vond de opdracht erg leuk omdat het niet alleen progammeren was maar ook het tot leven brengen van onze code. Dit, en de combi van verschillende technieken, bracht een stuk samenhang tussen alle dingen die we de afgelopen jaren hebben geleerd bij het vak informatica. Ik ben geen informatica expert dus ik had best wel wat moeite met sommige onderdelen, maar daar vulden we elkaar mooi aan als een team. Ik ben erg tevreden over het resultaat dat we hebben neergezet.

## Slot
Na al die maanden is het project toch afgerond en gelukkig zijn we allemaal best blij en trots op het eindresultaat. Het proces duurde wel lang, maar we konden allemaal ons eigen ding doen en het is toch goedgekomen, ondanks de maatregelen ivm corona en het feit dat een aantal van ons ook corona heeft gehad in de afgelopen maanden. 
