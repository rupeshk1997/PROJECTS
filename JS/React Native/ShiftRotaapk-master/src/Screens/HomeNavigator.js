
import React, { useState } from 'react'
import { View, Text } from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import { Button } from 'react-native'
import DatePicker from 'react-native-date-picker'
import HomeScreen from './Home';
import HomePage from './HomePage';




const Stack = createNativeStackNavigator();
const  HomeNavigator=()=>{
    return (
      <NavigationContainer>
        <Stack.Navigator>
          <Stack.Screen name="Shift Rota by Ritesh" component={HomePage} />
        </Stack.Navigator>
      </NavigationContainer>
    );
  }
export default HomeNavigator;