
public class Chord extends Note{

	String root;
	int quality; //0 = minor, 1 = Major, 2 = diminished
	
	/**
	 * Constructor
	 * @pre root and quality != null
	 * @post creates Chord object
	 * @param root
	 * @param quality
	 * @param octave
	 * @param duration
	 */
	
	public Chord(String root, int quality, Integer octave, Integer duration)
	{
		super(root,octave,duration);
		this.root = root;
		this.quality = quality;
	}
	
	/**
	 * 
	 * @post returns Chord as string
	 */
	
	public String toString()
	{
		return this.root+""+((quality == 0)? "m" : (quality == 1)? "M" : "o")
				+((octave!=null)?octave:"")
				+((this.duration!=null)?"-1/"+this.duration:"");
	}
	
}
