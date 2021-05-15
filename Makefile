.PHONY: all clean

ALGORITHMS = crypto_sign/falcon-512

$(ALGORITHMS):
	cd $(ALGORITHMS) && $(MAKE)

clean:
	+$(MAKE) -C $(ALGORITHMS)

	
	
