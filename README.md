[](This file is part of linux-patches. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/libertine-linux/linux-patches/master/COPYRIGHT. No part of linux-patches, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.)
[](Copyright © 2016 The developers of linux-patches. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/libertine-linux/linux-patches/master/COPYRIGHT.)

# linux-patches

[linux-patches] is a collection of patches to apply to a [linux-stable](https://github.com/libertine-linux-forks/linux-stable) kernel. Ordinarily, Libertine Linux keeps patches inside the relevant package (in this case `linux_prep`). However, because this patch set is so large it is inefficient and unfeasible to apply it as part of the build. Additionally, the generation of new Linux `.config` files (which we use in `package-configurations` as `linux-prep.mk`) is made substantially easier if a patched kernel sourceis available.


## Applicable Linux Version

As of 2nd December 2016, these patches are for applying to the Linux 4.4 longterm stable releases.


## Origin of patches

* `bfs`: Brain Fuck Scheduler (BFS) and other Con Kolivas patches
	* Downloaded from <http://ck.kolivas.org/patches/4.0/4.4/4.4-ck1/patch-4.4-ck1.xz>
	* `mkdir -m 0755 -p patches/ck1; wget -q -O - http://ck.kolivas.org/patches/4.0/4.4/4.4-ck1/patch-4.4-ck1.xz | unxz >patches/ck1/patch-4.4-ck1.patch`
* grsecurity (and PaX) patches
	 * Are only publically available for the latest stable kernel release. They are not necessarily available publically without subscription for the latest longterm kernel release
	 * Alpine Linux maintains backports via their [aports package manager](git://git.alpinelinux.org/aports) in location `aports/main/linux-grsec/APKBUILD`
		 * Alpine Linux patches may be available via URLs such as `http://dev.alpinelinux.org/~ncopa/grsec/grsecurity-3.1-4.4.36-201604252206-alpine.patch`
		 * Sadly this URL is not secure


## Licensing

The license for this project is MIT. Individual patches may be licensed differently. The patches in `busybox/` and `other/` are part of this project.

[linux-patches]: https://github.com/libertine-linux/linux-patches "linux-patches GitHub page"
