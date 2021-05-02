public class ComposerBot {
	
	long seed;

	void Strategy(char strt, int initSeed) 
	{
		//////////////////////////////////////////////////
		//Step 1
		
		seed = initSeed;										//Example seed = 1359233
		int quality =(int)seed % 2;									//quality = 1359233 % 2= 1
		int scaleIdx =(int)seed % 12;								//scaleIdx = 1359233  % 12= 5
		seed = (int) seed / 3;										//seed = 1359233 / 3 = 453077
		Scale scale = CircleOfFifths.getScale(scaleIdx, quality);	//Scale selected:	F Major
		
		/////////////////////////////////////////////////
		//Step 2
		
		Note[] notes = scale.notes();		//Scale notes:F G A A# C D E
		Chord[] chords = scale.chords();	//Scale chords:FM Gm Am A#M CM Dm Eo
		
		//print name and quality
		System.out.println(CircleOfFifths.a[scaleIdx]+" "+((quality==1)?"Major":"minor"));
		
		////////////////////////////////////////////////
		//Step 3
		
		//how many chords in progression [3, 6]
		int noChords = (int) (seed % 3) + 3;	//noChords = (453077 % 3) + 3 = 5
		Chord[] progression = new Chord[noChords];
		
		//TODO
		for(int i = 0; i < notes.length-1;i++)
			System.out.print(notes[i].toString()+" ");
		System.out.print(notes[notes.length-1]+"\n");
		//System.out.println();
		
		//put in progression array the chords to use
		for (int i=0; i<noChords; i++)
		{
			int chordIdx =(int) seed % 7;		//chordIdx =	453077 % 3 = 2
			seed =(int)seed / 3;				//seed = 453077 / 3 = 151025
			progression[i] = chords[chordIdx];
		}
		
		//TODO
		//for(Chord c : progression)
			//System.out.print(c.toString()+" ");
		//System.out.println();
		
		for(int i = 0; i < progression.length-1;i++)
			System.out.print(progression[i].toString()+" ");
		System.out.print(progression[progression.length-1]+"\n");
		
		//////////////////////////////////////////////////
		//Step 4										//
		//////////////////////////////////////////////////
		
		String[] result = new String[200];
		int index = 0;
		
		if(strt == 'A')
		{
			
			//reset seed to initial value
			seed = initSeed;
			int progIdx = 0;
			int octave = 4;
			
			
			while (true)
				{
				
				if(seed < 10) 
				{
					exitFunc(result,index);
					break;
				}
					//break;    //end generation when seed is small
				
					// Chord duration denominator {2, 4, 8}
					int duration =(int) Math.pow(2, (seed % 3)+1);
					seed = (int) seed / 3;
					Chord chord = progression[progIdx];
					if (++progIdx >= noChords) 
						progIdx = 0;
						
					chord.octave = octave;
					chord.duration = duration;
					//print or add chord to String with: <chord><octave><1/duration>
					//System.out.print(chord.toString()+" ");
					result[index++]=chord.toString();
					
				}
			
			
		}
		else if(strt == 'B')
		{
			//reset seed to initial value
			seed = initSeed;
			int progIdx = 0;
			int octave = 4;
			while (true) {

				
				// Chord duration denominator {2, 4, 8}
				int duration = (int) Math.pow(2, (seed % 3)+1);	//duration= 2(45697852% 3) + 1 = 4
				seed = (int) seed / 3;							//seed = 45697852 / 3 = 15232617
				Chord chord = progression[progIdx];					//chord= progression[0]= F#o
				if (++progIdx >= noChords) 
					progIdx = 0;			//progIdx =1
								
				chord.octave = octave;
				chord.duration = duration;
				//print or add chord to String with: <chord><octave><1/duration>	F#o4-1/4
				
				//System.out.print(chord.toString()+" ");
				result[index++]=chord.toString();
				
				//number of notes between chords: [0, 3]
				int noNotes =(int)seed % 4;								//noNotes=15232617% 4= 1
				for (int i = 0; i < noNotes; ++i) 
				{
					if(seed < 10) 
					{
						exitFunc(result,index);
						return;
					}
							//end generation when seed is small
					
					int noteIdx = (int) seed % 7;						//noteIdx=15232617% 7 = 1
					// note duration denominator {2, 4, 8}
					int dur = (int) Math.pow(2, (seed % 3)+1);			//dur= 2(15232617% 3) + 1 = 2
					seed =(int) seed /3;								//seed = 15232617 / 3 = 5077539
					Note note = notes[noteIdx];							//note= notes[1]= F#
					
					//note.durationNum=1;
					note.duration = dur;
					note.octave = octave;
					
					//print or add note to String with: <note><octave><1/duration>
					//System.out.print(note.toString()+" ");
					result[index++]=note.toString();
				}
			}
		}
		/*
		if(index != 0)
		{
		for(int i = 0; i < index-1; i++)
			System.out.print(result[i]+" ");
		System.out.print(result[index-1]+"\n");
		}*/
		
		return;
	}
	
	/////////////////////////////
	
	void exitFunc(String[] result, int index)
	{
		if(index != 0)
		{
		for(int i = 0; i < index-1; i++)
			System.out.print(result[i]+" ");
		System.out.print(result[index-1]+"\n");
		}
	}
	
}
