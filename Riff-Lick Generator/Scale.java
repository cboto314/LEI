
public class Scale {

	Note[] notes;
	Chord[] chords;
	int quality; //0 = minor, 1 = Major
	
	int[] Major = new int[] { 1, 0, 0, 1, 1, 0, 2}; //I   ii  iii  IV  V  vi  viio
	int[] minor = new int[] { 0, 2, 1, 0, 0, 1, 1}; //i   ii0 III  iv  v  VI  VII
	
	public Scale(Note[] notes, int quality)
	{
		int size = notes.length;
		this.notes = new Note[size];
		for(int i = 0; i < size; i++)
			this.notes[i] = new Note(notes[i].pitch,notes[i].octave,notes[i].duration);
		this.chords = new Chord[size];
		this.quality = quality;
		getChords();
	}
	
	
	Note[] notes()
	{
		return notes;
	}
	
	Chord[] chords()
	{
		//if(chords.length == 0)
		//{
		//	chords = new Chord[size];
		//	getChords();
		//}
		
		return chords;
	}
	
	void getChords()
	{
		
		for(int i = 0; i < notes.length; i++)
		{
			if(quality == 0)
				chords[i] = new Chord(notes[i].pitch,minor[i],null,null);
			else if(quality == 1)
				chords[i] = new Chord(notes[i].pitch,Major[i],null,null);
		}
		
	}
	
}
