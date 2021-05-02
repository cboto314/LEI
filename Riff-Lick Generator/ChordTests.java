import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class ChordTests {

	@Test
	/*
	 * Tests constructor and toString()
	 * 
	 */
	void testConstructor() {
		assertEquals("Am4-1/2",	new Chord("A",0,4,2).toString());
		assertEquals("F#M3-1/8",	new Chord("F#",1,3,8).toString());
	}

}
