
public class CircleOfFifths {
	
	static final int SIZE_OF_SCALE = 7;
	
	public static String[] chromatic = new String[] {
			"C","C#","D","D#","E","F",
			"F#","G","G#","A","A#","B" 
	};
	
	static String[] a = new String[]{ 
			"C", "G", "D","A","E","B",
			"F#","C#","G#","D#","A#","F",
			"C", "G", "D","A","E","B",
			"F#","C#","G#","D#","A#","F"
			};	//circular array TODO perguntar prof
	
	static int[] Major = new int[] {0,2,4,11,1,3,5};
	static int[] minor = new int[] {0,2,9,11,1,8,10};

	static int translateIdx(int scaleIdx) 
	{
		String note = chromatic[scaleIdx];
		int realIdx = java.util.Arrays.asList(a).indexOf(note);
		return realIdx;
	}

	static Scale getScale(int scaleIdx, int quality)
	{
		/*
		 * quality => 1 = Major, 0 = minor
		 */
		
		scaleIdx = translateIdx(scaleIdx);
		
		Note[] notes = new Note[SIZE_OF_SCALE];
		
		for(int i = 0; i < 7; i++)
		{
			 notes[i]= new Note(
							((quality == 0)? a[scaleIdx + minor[i]] : (quality == 1) ? a[scaleIdx + Major[i]] : null)
							,null,null);
		}
		Scale scale = new Scale(notes,quality);
				
		return scale;
	}
	
}
