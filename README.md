### Etap III

## Przedstawienie projektu

### oop_warehouse_model

### Karol Musz

#
### 1. Cel projektu

Projekt zakłada stworzenie aplikacji umożliwiającej zarządzanie magazynem z wykorzystaniem 
programowania obiektowego w języku C++. Model magazynu będzie się składał z różnych powierzchni,
dla których możliwe będzie zdefiniowanie atrybutów. Użytkownik będzie mógł
definiować magazyn z poszczególnymi częściami składowymi i umieszczać w nich towar oraz nim zarządzać.


### 2.	Opis klas

* WarehouseModelApplication - klasa główna aplikacji która posiada statyczną metodę run() wywoływaną w
metodzie main(), która uruchomi całą aplikację.

* Interface: UIComponent - interface z wzorca dekorator który posiada metodę display(),
której implementacje będą odpowiadać za konkretne elementy UI, zastosowanie tego wzorca
pozwala utworzyć menu konsolowe użytkownika.

* ConcreteComponent - implementacja interfejsu UIComponent, tworząca nagłówek tego interface.

* StorageManagementManuDecorator – implementacja interfejsu UIComponent odpowiadający
za dodanie elementów UI magazynu.

* PackageManagementMenuDecorator - implementacja interfejsu UIComponent odpowiadający 
za dodanie elementów UI paczek.

* BaseDecorator - impl. interfejsu UIComponent dodaje inne, ozdobne elementy UI.

* Interface: Command - jest to interface z wzorca komenda, dzięki któremu będzie można
tworzyć różne implementacje komend, które będą uruchamiane w z klas dekoratora.

* StorageManagerCommand - implementacja interface Command - umożliwia modyfikację lub
usunięcie istniejącej przestrzeni magazynowej.

* DefineStorageCommand - implementacja interface Command - umożliwia dodanie nowej
przestrzeni magazynowej.

* DisplayCapacityCommand  - implementacja interface Command - umożliwia wyświetlenie
zajętości wielu przestrzeni magazynowych.

* UpdatePackageCommand - implementacja interface Command - umożliwia modyfikację istniejącej paczki.

* RemovePackageCommand - implementacja interface Command - umożliwia usunięcie istniejącej
paczki z przestrzeni magazynowej.

* AddPackageCommand - implementacja interface Command - umożliwia dodanie nowej paczki
do przestrzeni magazynowej.

* WarehouseStateManager - klasa która, będzie mogła posiadać tylko jedną instancję (singleton),
realizująca logikę zarządzania kolejkami (przestrzeniami magazynowymi) oraz będzie przechowywać te 
przestrzenie magazynowe.


### 3.	Diagram
![Diagram_klas__ETAP_II_Karol_Musz.png](documentation%2Fdiagram%2FDiagram_klas__ETAP_II_Karol_Musz.png)


### 4.	Repozytorium kodu

Poniżej znajduje się adres publicznego repozytorium z kodem projektu:

https://github.com/MuszKarol/oop_warehouse_model


### 5.	Podsumowanie

Projekt polega na stworzeniu aplikacji do zarządzania magazynem w języku C++. 
Użytkownik będzie mógł definiować i zarządzać magazynem oraz manipulować towarami. 
Wynikiem projektu jest utworzone oprogramowanie, które w intuicyjny sposób usprawnia procesy magazynowe.

