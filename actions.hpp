enum class Action {
    breed, // creatures are of the same species
    die,   // creature going to field with lower power than other creature
    kill,  // creature going to field with higher power than other creature
    eat    // herbivore when plant
};
