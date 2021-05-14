.PHONY: clean

ALGORITHMS = crypto_sign/falcon-512

$(ALGORITHMS):
	+$(MAKE) -C $(ALGORITHMS)

clean:
	+$(MAKE) -C $(ALGORITHMS)

	
	
