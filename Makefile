LIBOUT = liblzhl.a
LIBOBJS = HuffStat.o HuffStatTmp.o LZBuffer.o LZHL.o LZHLCompressor.o LZHLDecoderStat.o LZHLDecompressor.o LZHLEncoder.o LZHLEncoderStat.o
EXEOUT = test
EXEOBJS = test.o

$(EXEOUT): $(EXEOBJS) $(LIBOUT)
	$(CXX) -o $(EXEOUT) $(EXEOBJS) $(LIBOUT)

$(LIBOUT): $(LIBOBJS)
	$(AR) rcs $(LIBOUT) $(LIBOBJS)
    
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(LIBOBJS) $(EXEOBJS) $(LIBOUT) $(EXEOUT)
