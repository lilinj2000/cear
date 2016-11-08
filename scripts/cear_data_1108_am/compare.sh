#!/bin/sh

awk '{printf "%s\t%s\t%s\t%s\t%s\t%s\n",$1,$4,$5,$6,$7,$8}' cear_citicsf.data > citicsf.data

awk '{printf "%s\t%s\t%s\t%s\t%s\t%s\n",$1,$4,$5,$6,$7,$8}' cear_ht.data > ht.data

awk '{printf "%s\t%s\t%s\t%s\t%s\t%s\n",$1,$4,$5,$6,$7,$8}' cear_sywg.data > sywg.data
