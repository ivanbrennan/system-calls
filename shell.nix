# To update: nix/update-nixpkgs [REVISION]
{ nixpkgs ? import ./nix/nixpkgs.nix }:

let
  pkgs = nixpkgs { };

in with pkgs; mkShell {
  name = "system-calls";
  version = "1.0.0";

  buildInputs = [
    stdenv
    git
    gcc
  ];

  shellHook = builtins.readFile ./nix/prompt.sh + ''
    source ${pkgs.git}/etc/bash_completion.d/git-prompt.sh
    source ${pkgs.git}/etc/bash_completion.d/git-completion.bash
  '';
}
