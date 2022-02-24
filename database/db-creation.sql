/* Beschrijf de tabellen die je nodig hebt*/

CREATE TABLE runs (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  stamp DATETIME NOT NULL
);

CREATE TABLE sensorData (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  run INTEGER NOT NULL,
  stamp DATETIME NOT NULL,
  aantalKnikkers INTEGER
);

CREATE TABLE instellingen (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  run INTEGER NOT NULL,
  stamp DATETIME NOT NULL,
  wachttijdPoort INTEGER NOT NULL,
  wisselStaatRechts INTEGER NOT NULL
);

