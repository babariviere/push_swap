with import <nixpkgs> {};

stdenv.mkDerivation rec {
  name = "push_swap-${version}";
  version = "1.0";

  buildInputs = [
    clang
    ];

  src =./.;
}
