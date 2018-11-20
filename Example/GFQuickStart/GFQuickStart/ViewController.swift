//
//  ViewController.swift
//  GFQuickStart
//
//  Created by Ben Tally on 11/19/18.
//  Copyright © 2018 Ben Tally. All rights reserved.
//

import UIKit
import GeoFrenzy

class ViewController: UIViewController, FencingAgentDelegate  {
    var totalFences = 0

    @IBOutlet weak var fenceName: UILabel!
    @IBOutlet weak var colorView: UIView!
    @IBOutlet weak var fenceDomain: UILabel!
    @IBOutlet weak var fencePointCount: UILabel!
    @IBOutlet weak var fenceDwellTime: UILabel!
    
    func approachingFences(_ fenceSet: NSMutableSet) {
        
    }
    
    func enteringFences(_ fenceSet: NSMutableSet) {
        
    }
    
    func exitingFences(_ fenceSet: NSMutableSet) {
        
    }
    
    func leftFences(_ fenceSet: NSMutableSet) {
        totalFences -= 1
        if (totalFences < 1) {
            colorView.alpha = 0
            fenceName.text = "None"
            fenceDomain.text = "None"
            fencePointCount.text = "None"
            fenceDwellTime.text = "None"
        }
    }
    
    func dwelling(insideFences fenceSet: NSMutableSet) {
        totalFences += 1
        if (totalFences > 0) {
            colorView.alpha = 1
            let fence = fenceSet.allObjects[0] as! SmartFence
            fenceName.text = Utilities .getLastLabel(fence.id)
            fenceDomain.text = Utilities .removeLabel(fence.id, atLevel: 0)
            var pointCount = fence.geometry.count
            pointCount -= 1
            fencePointCount.text = String(pointCount)
            fenceDwellTime.text = String(fence.dwellTime)
        }
    }
    
    func conflictFences(_ fenceSet: NSMutableSet) {
        
    }
    

    override func viewDidLoad() {
        let fac = FencingAgentConfig.sharedInstance()
        fac?.addGeoDomain(".place.geonetwork.globalmapdemo")
        fac?.detectApproaching = true;
        fac?.controlPanelIdx = "1d"
        fac?.voiceSynth = true
        fac?.annunciateFactoryStages = true
        
        let fa = FencingAgent(config:fac)
        
        fa.registerCommandHandler("setColorWithRuleColor", withPath: ".place.controltype.geonetwork.gfquickstart.displaycolor", on: self)
        
        print ("ambient: \(fa.ambientFences.count)")
        
        fa.delegate = self
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    @objc func setColor(ruleColor:UIColor) {
        colorView.backgroundColor = ruleColor
    }
    
}

