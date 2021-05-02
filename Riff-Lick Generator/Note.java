
public class Note {
	
	public String pitch;
	public Integer octave;
	//public Integer durationNum;
	public Integer duration;
	
	public Note(String pitch, Integer octave, Integer duration)
	{
		if(!checkPitch(pitch.charAt(0)) || (pitch.length() > 1 && !checkStep(pitch.charAt(1)))) {
			
			System.out.println("Invalid pitch class");
			return;			
			
		}
		this.pitch = pitch;
		this.octave = octave;
		this.duration = duration;
		//this.durationDen = durationDen;
	}

	boolean checkPitch(char P) {
		
		return (P >= 65) && (P <= 71);
	}
	
	boolean checkStep(char S) {
		
		return (S == '#' || S == '\0');
		
	}
	
	public String toString()
	{
		return pitch+""+((octave!=null)?octave:"")+""
					   +((duration!=null)?"-1/"+duration:"");
	}
	
}
