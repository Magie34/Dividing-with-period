#pragma once

float Teilen_mit_Periode(float Geteielt, float Teiler, float * sekond_output) {

	int i = 0;
	int counter = 0;
	int Datacount = 0;
	float multiplier = 1.0;
	float output = 0;
	int periode = 0;

	std::vector<Perioden_Speicher> Data;
	std::vector<int> List_of_numbers;

	Data.push_back({});

	while (i == 0) {
		if (Geteielt >= Teiler) {
			Geteielt -= Teiler;
			counter++;
			if (Geteielt <= 0) {
				i = 1;
			}
		}
		else {

			Data[Datacount].zwischezahl = Geteielt;
			Geteielt = Geteielt * 10;
			Data[Datacount].weiterrechnen = Geteielt;
			Data.push_back({});

			output = output + counter * multiplier; //Fügt aktuelle Zahl eine Stelle hinter letzter zahl an
			if (multiplier < 1) {
				List_of_numbers.push_back(counter);
			}
			counter = 0;
			multiplier = multiplier / 10; //Stelle eins zurücksetzen
			for (int a = 0; a < Data.size() && a < Datacount; a++) {
				if (Data[a].weiterrechnen == Data[Datacount].weiterrechnen /* && Data[a].zwischezahl == Data[Datacount].zwischezahl */) {
					int c = 1;

					for (int b = List_of_numbers.size() - 1; b >= a; b--) { //Fügt die wiederholung aus der Liste Data in eine einzige int ein

						periode = periode + List_of_numbers[b] * c;
						c = c * 10;
					}
					i = 1;
				}
			}
			Datacount++;
		}
	}
	*sekond_output = periode;
	return output;

}
